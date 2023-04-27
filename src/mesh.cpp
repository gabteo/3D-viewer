#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <filesystem>
//#include <boost>
using namespace std;
//using namespace std::filesystem;

//#include <GL/gl.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../includes/gutils.h"
#include "../includes/input.h"
#include "../includes/colors.h"
#include "../includes/shadersUtils.h"
#include "../includes/window.h"
#include "../includes/errorType.h"
#include "../includes/logging.h"
//#include "../includes/model.h"
#include "../lib/utils.h"
#include <math.h>



// camera
/* Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true; */

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void initData()
{
    // Set triangle vertices.
    float vertices[] = {
	// First triangle
        // coordinate     color
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        // Second triangle
        // coordinate     color
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f
    };
    
    // Vertex array.
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertex buffer
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    
    // Set attributes.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind Vertex Array Object.
    glBindVertexArray(0);
}

/** Create program (shaders).
 * 
 * Compile shaders and create the program.
 */
void initShaders()
{
    // Request a program and shader slots from GPU
    //program = createShaderProgram(vertex_code, fragment_code);
    program = createShaderProgram(loadCodeFromFile(codes::vertexCode), loadCodeFromFile(codes::fragmentCode));
}

void renderScene(){
    //printf("Rendering...\n");
    cout << "Rendering..." <<  endl;

	//xPos = 0.3;
	setBackgroundColor(lightBrown);
    //setBackgroundColor(rgbToFloat(3, 169, 252));
    //glClearColor(0.87, 0.72, 0.53, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

	// TRANSLATE
	glm::mat4 T = glm::translate(glm::mat4(1.0f), glm::vec3(xPos,yPos,zPos));

	// ROTATE
	// Z
	glm::mat4 Rz = glm::rotate(glm::mat4(1.0f), glm::radians(zRotation), glm::vec3(0.0f,0.0f,1.0f));
	// Y
	glm::mat4 Ry = glm::rotate(glm::mat4(1.0f), glm::radians(yRotation), glm::vec3(0.0f,1.0f,0.0f));
	// X
	glm::mat4 Rx = glm::rotate(glm::mat4(1.0f), glm::radians(xRotation), glm::vec3(1.0f,0.0f,0.0f));

	// SCALE
   	glm::mat4 S = glm::scale(glm::mat4(1.0f), glm::vec3(xScale, yScale, zScale));

	glm::mat4 M = glm::mat4(1.0f);
	M = T*Rz*Ry*Rx*S;

	glUseProgram(program);
    glBindVertexArray(VAO);

	unsigned int loc = glGetUniformLocation(program, "model");

	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(M));


	
	if(wireframeView)
	{
  		glDrawArrays(GL_LINE_LOOP, 0, 6);
	}
	else 
	{
  		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	glutSwapBuffers();
}

error_type_t setupGlut(int* argc, char **argv){
 	// init GLUT and create window
    glutInit(argc, argv);
    //glutInit(&argc, argv);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);

    //glutInitWindowPosition(int x, int y);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(win_width, win_height);

	window = glutCreateWindow(argv[1]);
	return Success;
}

error_type_t registerCallbacks() {
	// register callbacks
	glutReshapeFunc(reshape);
	glutDisplayFunc(renderScene); 
	glutKeyboardFunc(keyboard);
	//glutMouseFunc(mouse);
	glutSpecialFunc(transformKeyPress);
	return Success;
}

logging* logging::loggingInstance = nullptr;

int main(int argc, char **argv) 
{

	logging* logger = logging::getInstance();
	logger->setLogLevel(DEBUG);
	logger->log(DEBUG, "Hello, OpenGL! I'm debug.");
	logger->log(ERROR, "Hello, OpenGL! I'm error.");


	static char* filepath;
	if(argc > 1)
	{
		filepath = argv[1];
		//logger->log(INFO, "Abrindo arquivo...");

	}
	else
	{
		filepath = DEFAULT_FILE_PATH;
		logger->log(ERROR, "ERRO: Nenhum arquivo recebido! Carregando arquivo padrão...");

	}



	logger->log(INFO, filepath);

	FILE *f = fopen(filepath, "r");

	if(f == nullptr)
	{
		logger->log(ERROR, "ERRO: Não foi possível abrir o arquivo.");
	}

	//boost::filesystem::path p("C:\\folder\\foo.txt");
	//filesystem FileSystem;
	//Model ourModel(filepath);
	
	
	setupGlut(&argc, argv);
	glewInit(); 
	registerCallbacks();

    initData();
    initShaders();
        	
	
	// enter GLUT event processing cycle
	glutMainLoop(); 
	//glutDestroyWindow(glutGetWindow());
	return 0;
}

