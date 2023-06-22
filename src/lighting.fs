#version 330 core

int CIMA = 0;
int BAIXO = 1;
int FRENTE = 2;
int TRAS = 3;
int DIREITA = 4;
int ESQUERDA = 5;


uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float ambientAtenuation;
uniform vec3 lightPosition;
uniform vec3 viewPos;
uniform samplerCube cubemap;

out vec4 FragColor;
in vec3 TexCoords;  //posição original
in vec3 TexDir;  //posição original
in vec3 normalCorrected;
in vec3 FragPos;


uniform sampler2D myTexture;

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

    int face;
    if(abs(FragPos.x) >= abs(FragPos.y) && abs(FragPos.x) >= abs(FragPos.z)) {
        if(FragPos.x > 0) {
            face = DIREITA;
        }
        else {
            face = ESQUERDA;
        }
    }
    else if (abs(FragPos.y) >= abs(FragPos.x) && abs(FragPos.y) >= abs(FragPos.z)) {
        if(FragPos.y > 0) {
            face = CIMA;
        }
        else {
            face = BAIXO;
        }
    }
    else if (abs(FragPos.z) > abs(FragPos.y) && abs(FragPos.z) > abs(FragPos.x)) {
        if(FragPos.z > 0) {
            face = FRENTE;
        }
        else {
            face = TRAS;
        }
    }
    //FragColor = texture(texture_diffuse1, TexCoords);
    //FragColor = vec4(0.6, 0.2, 0.6, 1.0);
    //FragColor = vec4((normalCorrected+0.5)*lightColor, 1.0);
    //FragColor = vec4(lightColor, 1.0);
    //FragColor = vec4((normalCorrected+0.5) * lightColor * objectColor * ambientAtenuation, 1.0);
    FragColor = vec4(lightColor * objectColor * (ambientAtenuation + diffuse + specular), 1.0) * (texture(cubemap, TexCoords));
    //FragColor = vec4(lightColor * objectColor * (ambientAtenuation + specular), 1.0);
}