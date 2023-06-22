#version 330 core

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float ambientAtenuation;
out vec4 FragColor;

in vec2 TexCoords;
in vec3 normalCorrected;


uniform sampler2D texture_diffuse1;

void main()
{   
    //FragColor = texture(texture_diffuse1, TexCoords);
    //FragColor = vec4(0.6, 0.2, 0.6, 1.0);
    //FragColor = vec4((normalCorrected+0.5)*lightColor, 1.0);
    //FragColor = vec4(lightColor, 1.0);
    //FragColor = vec4((normalCorrected+0.5) * lightColor * objectColor * ambientAtenuation, 1.0);
    FragColor = vec4(lightColor * objectColor * ambientAtenuation, 1.0);
}