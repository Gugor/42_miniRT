
#include "scene.h"

void	test_lst()
{
	t_lst		*shapes;
	t_sphere	*sphere = (t_sphere *)malloc(sizeof(t_sphere));	
	t_plane		*plane = (t_plane *)malloc(sizeof(t_plane));	

	add_node_to(shapes, sphere, SPHERE);
	add_node_to(shapes, plane, PLANE);
}

int main (void)
{


}