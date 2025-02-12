# miniRT

miniRT is a simple raytracer written in C. It implements basic ray tracing techniques to render simple geometric objects with lighting and reflections. This project is compiled using Make with gcc and is designed for Linux systems.
![render-burj-khalifa](https://github.com/user-attachments/assets/d82d017e-f15e-46c0-8159-48c051b9aed2)
# Features

Intersection calculation for:

1. Sphere

2. Cylinder

3. Plane

4. Bonus: Square

5. Ambient lighting

6. Multiple light sources

7. Specular reflections using the Phong reflection model

# Installation & Compilation

## Clone the repository:
This proyect has being done for Linux systems. Has not support for other OS.
```bash
git clone git@github.com:Gugor/42_miniRT.git miniRT
cd miniRT
```

## Compile the project using make:
```bash
make
```
Usage

Run the program with a scene file:

./miniRT scenes/<scene_file>

# Dependencies

- gcc (GNU Compiler Collection)
- Make
- Standard C libraries
  
# Authors
Developed by [Marti Marsa] and [Hugo Montoya]

# Examples
[Ambient Light], [Lights]x4, [Sphere], [Cylinder]x2, [Plane]x5, [Square]
![rt-room](https://github.com/user-attachments/assets/0520ce42-64ed-4717-86b8-9d9705a5a429)


