#version 330 core
out vec4 FragColor;
  
in vec3 worldColor;

void main()
{
    FragColor = vec4(worldColor, 1.0);
}