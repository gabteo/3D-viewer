#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 aTexCoords;

//out vec2 TexCoords;
out vec4 positionMod;

uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

void main()
{
    //TexCoords = aTexCoords;  
    positionMod = model * vec4(position.x, position.y, position.z, 1.0);  
    gl_Position = positionMod;

}