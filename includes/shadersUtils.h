#ifndef SHADERS_UTILS_H
#define SHADERS_UTILS_H

enum class codes {
    vertexCode,
    fragmentCode
};

/** Vertex shader. */
static const char *vertex_code = "\n"
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
static const char *fragment_code = "\n"
"#version 330 core\n"

"in vec3 vColor;\n"
//"layout (location = 0) out vec4 color;\n"
"out vec4 FragColor;\n"
"\n"
"void main()\n"
"{\n"
"    FragColor = vec4(vColor, 1.0f);\n"
"}\0";

/** Program variable. */
static int program;
/** Vertex array object. */
static unsigned int VAO;
/** Vertex buffer object. */
static unsigned int VBO;
static unsigned int lightVBO;

static unsigned int lightVAO;

/**
 * Loads a file containg the vertex shader or the fragment shader
*/
char* loadCodeFromFile(codes code);


/** Create program (shaders).
 * Compile shaders and create the program.
*/
//void initShaders();


#endif