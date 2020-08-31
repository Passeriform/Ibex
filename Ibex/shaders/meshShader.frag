#version 330 core
out vec4 outColor;
  
in vec3 inColor;
uniform vec3 lightColor;

void main()
{
    outColor = vec4(lightColor * inColor, 1.0);
}