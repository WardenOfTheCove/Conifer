#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
uniform mat3 camera;
out vec4 colour;
void main() {
    mat3 camera_position = camera + aPos;
    gl_Position = vec4(camera_position[0], 1.0);
    colour = vec4(aColor, 1.0);
}