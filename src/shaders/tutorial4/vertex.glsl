#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
uniform float uAlpha;
out vec4 oColor;

void main() {
    oColor = vec4(aColor, uAlpha);
    gl_Position = vec4(aPosition, 1.0f);
}
