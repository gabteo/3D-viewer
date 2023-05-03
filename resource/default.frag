#version 330
out vec4 FragColor;

in vec4 fragColor;
in vec3 Normal;  
in vec3 FragPos;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
	float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float constant = 1.0;
    float linear = 0.09;
    float quadratic = 0.032;
    float distance = length(lightPos - FragPos);
    float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    vec3 specular = specularStrength * spec * lightColor;  
        
    vec3 result = ((ambient + diffuse + specular) * objectColor) * attenuation;
    FragColor = vec4(result, 1.0);
}