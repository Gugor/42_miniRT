
# include "shapes.h"
# include "shape-maths.h"

static int SolveCubic(double c[4], double roots[3]) {
    double a = c[0], b = c[1], d = c[2], e = c[3];
    if (a == 0) return 0;

    b /= a; d /= a; e /= a;
    a = 1.0;

    double Q = (b*b - 3*d)/9.0;
    double R = (2*b*b*b - 9*b*d + 27*e)/54.0;
    double D = Q*Q*Q - R*R;

    if (D >= 0) {
        double theta = acos(R/sqrt(Q*Q*Q));
        roots[0] = -2*sqrt(Q)*cos(theta/3) - b/3;
        roots[1] = -2*sqrt(Q)*cos((theta + 2*M_PI)/3) - b/3;
        roots[2] = -2*sqrt(Q)*cos((theta - 2*M_PI)/3) - b/3;
        return 3;
    } else {
        double A = -copysign(1.0, R) * pow(fabs(R) + sqrt(-D), 1/3.0);
        double B = (A == 0) ? 0 : Q/A;
        roots[0] = (A + B) - b/3;
        return 1;
    }
}

static int SolveQuartic(double coeffs[5], double roots[4]) {
    double a = coeffs[0], b = coeffs[1], c = coeffs[2], d = coeffs[3], e = coeffs[4];
    if (a == 0) return 0;

    // Normalizar coeficientes
    b /= a; c /= a; d /= a; e /= a;
    a = 1.0;

    // Resolver la resolvente cúbica: y³ + py² + qy + r = 0
    double p = -c;
    double q = b*d - 4*e;
    double r = -b*b*e + 4*c*e - d*d;
    double cubic_coeffs[4] = {1.0, p, q, r};
    double y_roots[3];
    int num_y_roots = SolveCubic(cubic_coeffs, y_roots);

    double y = (num_y_roots > 0) ? y_roots[0] : 0.0;

    // Calcular raíces cuadradas
    double sqrt_R = sqrt(b*b/4.0 - c + y);
    double sqrt_D = (sqrt_R == 0) ? sqrt(y*y - 4*e) : sqrt(b*y/2.0 - d)/sqrt_R;

    // Calcular raíces cuárticas
    roots[0] = (-b/2.0 + sqrt_R + sqrt_D)/a;
    roots[1] = (-b/2.0 + sqrt_R - sqrt_D)/a;
    roots[2] = (-b/2.0 - sqrt_R + sqrt_D)/a;
    roots[3] = (-b/2.0 - sqrt_R - sqrt_D)/a;

    return 4; // Devuelve 4 raíces (pueden incluir complejas)
}

int hit_torus(void *shp, const t_ray *ray, t_interval *ray_limits,
t_hit_data *rec) 
{
    t_torus *t = (t_torus *)shp;
	t_tor_hit	hitd;
    
    // Proyecciones en el eje del toroide (A)
    hitd.oc = sub_v3(ray->origin, t->pos);
    hitd.proj_oc_axis = dot(&hitd.oc, &t->axis);       // OC · A
    hitd.proj_dir_axis = dot(&ray->direction, &t->axis); // D · A
    
    // Componentes perpendiculares al eje (radio efectivo)
    hitd.oc_perp = sub_v3(hitd.oc, scale_v3(t->axis, hitd.proj_oc_axis)); // OC⊥ = OC - (OC·A)A
    hitd.dir_perp = sub_v3(ray->direction, scale_v3(t->axis, hitd.proj_oc_axis)); // D⊥ = D - (D·A)A
    
    // Coeficientes de la ecuación cuártica (simplificados)
    hitd.a = dot(&hitd.dir_perp, &hitd.dir_perp);                    // ||D⊥||²
    hitd.b = 2 * dot(&hitd.oc_perp, &hitd.dir_perp);                 // 2 OC⊥ · D⊥
    hitd.c = dot(&hitd.oc_perp, &hitd.oc_perp) + t->R * t->R - t->r * t->r; // ||OC⊥||² + R² - r²
    hitd.d = 2 * hitd.proj_oc_axis * hitd.proj_dir_axis;             // 2 (OC·A)(D·A)
    hitd.e = hitd.proj_oc_axis*hitd.proj_oc_axis - t->r * t->r;        // (OC·A)² - r²
    
    // Ecuación cuártica: (a t² + b t + c)² + (d t + e)² = 4 R² (a t² + b t + c)
    double coeffs[5] = {
        hitd.a * hitd.a + hitd.d * hitd.d - 4 * t->R * t->R * hitd.a,    // t⁴
        2 * hitd.a * hitd.b + 2 * hitd.d * hitd.e - 4 * t->R * t->R * hitd.b,// t³
        hitd.b * hitd.b + 2 * hitd.a * hitd.c + hitd.e * hitd.e - 4 * t->R * t->R * hitd.c, // t²
        2 * hitd.b * hitd.c,                        // t¹
        hitd.c * hitd.c                           // t⁰
    };
    
    // Resolver ecuación cuártica
    double roots[4];
    int num_roots = SolveQuartic(coeffs, roots);
    
    // Buscar la raíz válida más pequeña
    double t_min = INFINITY;
    for (int i = 0; i < num_roots; ++i) {
        if (interval_contains(ray_limits, roots[i]) && roots[i] < t_min) {
            t_min = roots[i];
        }
    }
    
    if (t_min == INFINITY) return 0;
    
    // Calcular datos de intersección
    rec->t = t_min;
    rec->hit = at((t_ray *)ray, t_min);
    rec->shape_pos = t->pos;
    rec->rgb = t->rgb;
    
    // Calcular normal usando proyecciones
    t_vec3 hit_local = sub_v3(rec->hit, t->pos);
    double proj_hit_axis = dot(&hit_local, &t->axis);
    t_vec3 hit_perp = sub_v3(hit_local, scale_v3(t->axis, proj_hit_axis));
    
    hitd.normal = sub_v3(
        scale_v3(hit_perp, 2 * (1 - t->R / length_v3(hit_perp))),
        scale_v3(t->axis, 2 * proj_hit_axis)
    );
    
    normalize_v3(hitd.normal);
    set_face_normal(ray, &hitd.normal, rec);
    
    return 1;
}