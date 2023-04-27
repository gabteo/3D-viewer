#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//#include <GL/gl.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "../includes/gutils.h"
#include "../includes/input.h"
#include "../includes/colors.h"
#include "../includes/shadersUtils.h"
#include "../includes/window.h"
#include "../includes/errorType.h"
#include "../includes/logging.h"
#include <math.h>




void renderScene(){
    //printf("Rendering...\n");
    cout << "Rendering..." << endl;

	setBackgroundColor(lightBrown);
    //setBackgroundColor(rgbToFloat(3, 169, 252));
    //glClearColor(0.87, 0.72, 0.53, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

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

	setupGlut(&argc, argv);
	glewInit(); 
	registerCallbacks();

    //initData();
    //initShaders();
        
        

	
	
	// enter GLUT event processing cycle
	glutMainLoop(); 
	//glutDestroyWindow(glutGetWindow());
	return 0;
}

