#version 330 core

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float ambientAtenuation;
uniform vec3 lightPosition;
uniform vec3 viewPos;

out vec4 FragColor;
in vec2 TexCoords;
in vec3 normalCorrected;
in vec3 FragPos;


uniform sampler2D texture_diffuse1;

void main()
{   
    vec3 norm = normalize(normalCorrected);
    vec3 lightDirection = normalize(lightPosition - FragPos);  
    float diffuse = max(dot(norm, lightDirection), 0.0);
    
    float specularStrength = 0.7;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDirection, norm); 

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
    vec3 specular = specularStrength * spec * lightColor; 
    //FragColor = texture(texture_diffuse1, TexCoords);
    //FragColor = vec4(0.6, 0.2, 0.6, 1.0);
    //FragColor = vec4((normalCorrected+0.5)*lightColor, 1.0);
    //FragColor = vec4(lightColor, 1.0);
    //FragColor = vec4((normalCorrected+0.5) * lightColor * objectColor * ambientAtenuation, 1.0);
    FragColor = vec4(lightColor * objectColor * (ambientAtenuation + diffuse + specular), 1.0);
    //FragColor = vec4(lightColor * objectColor * (ambientAtenuation + specular), 1.0);
}