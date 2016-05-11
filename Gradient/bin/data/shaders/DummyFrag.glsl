#version 120

#define PI 3.14159265358
//uniform float time;
//uniform float numBars;
uniform vec2 resolution;
uniform vec2 direction;
uniform vec4 color1;
uniform vec4 color2;
uniform float speed;
uniform float time;
uniform float frequency;
varying vec2 texCoord;

void main() {
	//The position of the 
    vec2 position = texCoord / resolution.xy;
    float percentage = sin(frequency * (position.x * direction.x + position.y * direction.y) + time * speed);

    //position *= direction;
    vec4 newColor1 = color1 * percentage;
    vec4 newColor2 = color2 * (1.0 - percentage);

    gl_FragColor = newColor1 + newColor2;
}