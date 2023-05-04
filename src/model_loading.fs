#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 normalCorrected;

uniform sampler2D texture_diffuse1;

void main()
{   
    float ambient = 0.4;
    //FragColor = texture(texture_diffuse1, TexCoords);
    //FragColor = vec4(0.6, 0.2, 0.6, 1.0);
    FragColor = vec4(normalCorrected, 1.0) * ambient;
}