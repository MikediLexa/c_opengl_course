#version 330 core
layout (location = 0) in vec2 aPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
    gl_Position = u_proj * u_view * u_model * vec4(aPos, 0.0, 1.0);
}