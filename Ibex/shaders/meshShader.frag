#version 330 core
out vec4 outColor;
  
in vec3 objColor;
uniform vec3 lightColor;

void main()
{
    outColor = vec4(lightColor * objColor, 1.0);
}
