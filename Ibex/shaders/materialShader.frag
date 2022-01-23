#version 330 core
out vec4 outColor;
  
in vec3 fragPos;
in vec3 objNormal;
in vec3 objColor;
in vec3 textureCoords;

struct Material {
    vec3 ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    vec3 ambient, diffuse, specular;
    
    // Ambient Lighting
    // TODO: Experiment with custom ambient value in place of material.diffuse
    ambient = (light.ambient * vec3(texture(material.diffuse, textureCoords.xy)));
    
    // Diffuse Lighting
    vec3 norm = normalize(objNormal);
    vec3 lightDir = normalize(light.position - fragPos);

    float diffuseImpact = max(dot(norm, lightDir), 0.0);
    
    diffuse = light.diffuse * (diffuseImpact *  vec3(texture(material.diffuse, textureCoords.xy)));
    
    // Specular Lighting
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    
    float specularImpact = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    specular = light.specular * (specularImpact * vec3(texture(material.specular, textureCoords.xy)));

    // Resultant
    outColor = vec4((ambient + diffuse + specular) * objColor, 1.0);
}
