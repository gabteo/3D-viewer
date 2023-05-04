#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
//layout (location = 2) in vec2 aTexCoords;
//in vec3 normal;
out vec3 normalCorrected;

//out vec2 TexCoords;
out vec4 positionMod;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    //TexCoords = aTexCoords;  
    positionMod = projection * view * model * vec4(position.x, position.y, position.z, 1.0);  
    gl_Position = positionMod;
    positionMod = model * vec4(position.x, position.y, position.z, 1.0);
    normalCorrected = mat3(transpose(inverse(model))) * normal;

}