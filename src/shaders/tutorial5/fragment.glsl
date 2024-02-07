#version 330 core

out vec4 oFragColor;
in vec2 oTexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;


void main() {
    oFragColor = mix(texture(texture1, oTexCoord), texture(texture2, oTexCoord), 0.5f);
}
