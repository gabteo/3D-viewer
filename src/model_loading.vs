#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
//layout (location = 2) in vec2 aTexCoords;
//in vec3 normal;
out vec3 normalCorrected;
out vec3 FragPos;

//out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    //TexCoords = aTexCoords;  
    gl_Position = projection * view * model * vec4(position, 1.0);  
    
    FragPos = vec3(model * vec4(position, 1.0));
    normalCorrected = mat3(transpose(inverse(model))) * normal;

}