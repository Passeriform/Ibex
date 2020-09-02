#version 330 core
out vec4 outColor;
  
in vec3 fragPos;
in vec3 objColor;
in vec3 objNormal;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform float ambientStrength;
uniform float specularStrength;
uniform float shininess;

void main()
{
    vec3 ambient, diffuse, specular;
    
    // Ambient Lighting
    ambient = (ambientStrength * lightColor);
    
    // Diffuse Lighting
    vec3 norm = normalize(objNormal);
    vec3 lightDir = normalize(lightPos - fragPos);

    float diffuseImpact = max(dot(norm, lightDir), 0.0);
    
    diffuse = diffuseImpact * lightColor;
    
    // Specular Lighting
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    
    float specularImpact = pow(max(dot(viewDir, reflectDir), 0.0), shininess);

    specular = specularStrength * specularImpact * lightColor;

    // Resultant
    outColor = vec4((ambient + diffuse + specular) * objColor, 1.0);
}
