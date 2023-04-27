//#include "myLibsGL.h"

/** Vertex shader. */
const char *vertex_code = "\n"
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 vColor;\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"    vColor = color;\n"
"}\0";

/** Fragment shader. */
const char *fragment_code = "\n"
"#version 330 core\n"

"in vec3 vColor;\n"
//"layout (location = 0) out vec4 color;\n"
"out vec4 FragColor;\n"
"\n"
"void main()\n"
"{\n"
"    FragColor = vec4(vColor, 1.0f);\n"
"}\0";

#ifndef COLORS_H
#define COLORS_H

struct color
    {
        float r;
        float g;
        float b;
    };

static color lightBrown = 
{
    .r = 0.87,
    .g = 0.72,
    .b = 0.53
};


#endif


#ifndef GUTILS_H
#define GUTILS_H

//screen
#define HD_WIN_WIDTH 1280
#define HD_WIN_HEIGH 720

#define WIN_WIDTH HD_WIN_WIDTH
#define WIN_HEIGH HD_WIN_HEIGH

static int win_width = WIN_WIDTH;
static int win_height = WIN_HEIGH;

/**------------------------------------------------*/

enum class lista 
{
    lista0,
    lista1,
    lista2,
    lista3,
};

static lista listaAtual = lista::lista3;
/*-------------------------------------------*/

//Geometry
enum { X_AXIS, Y_AXIS };

struct point
{
    float x;
    float y;
    float z;
};

typedef point vector3;

struct vector4
{
    float x;
    float y;
    float z;
    float w;
};

 


#endif



#ifndef INPUT_H
#define INPUT_H

#endif

#ifndef SHADERS_UTILS_H
#define SHADERS_UTILS_H

enum class codes {
    vertexCode,
    fragmentCode
};

/** Program variable. */
static int program;
/** Vertex array object. */
static unsigned int VAO;
/** Vertex buffer object. */
static unsigned int VBO;




#endif


