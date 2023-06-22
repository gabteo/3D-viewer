#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <filesystem>
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
#include "../includes/model.h"
#include "../includes/utils.h"
#include <math.h>




// camera
//Camera camera(glm::vec3(0.0f, 0.0f, -3.0f));
/*float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true; */

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

Shader* lightingShader;
Shader* lightCubeShader;
Model* modelP;
Model* lightCube;

logging* logging::loggingInstance = nullptr;
logging* logger = logging::getInstance();

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);


/** Create program (shaders).
 * 
 * Compile shaders and create the program.
 */
void initShaders()
{
    // Request a program and shader slots from GPU
    //program = createShaderProgram(vertex_code, fragment_code);
    //program = createShaderProgram(loadCodeFromFile(codes::vertexCode), loadCodeFromFile(codes::fragmentCode));
}

void initLightVAO(){
	// light VAO
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	// we only need to bind to the VBO, the container's VBO's data already contains the data.
    glGenBuffers(1, &lightVBO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	// set the vertex attribute 
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);
}

void initDefaultVAO(){
    // Vertex array.
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Vertex buffer
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
    
    // Set attributes.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    // Unbind Vertex Array Object.
    glBindVertexArray(0);
}

void initVAO()
{
	initDefaultVAO();
	initLightVAO();
}

void renderScene(){
    cout << "Rendering..." <<  endl;

	//xPos = 0.3;
	//setBackgroundColor(darkBrown);
    //setBackgroundColor(rgbToFloat(10, 0, 15));
    setBackgroundColor(rgbToFloat(45, 64, 160));
    //glClearColor(0.87, 0.72, 0.53, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	lightingShader->use();

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

	// Set model matrix
	glm::mat4 M = glm::mat4(1.0f);
	M = T*Rz*Ry*Rx*S;

	lightingShader->setMat4("model", M);

	glm::mat4 projection;
	{
		if(ortho)
		{
			projection = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, 0.1f, 100.0f);
			lightingShader->setMat4("projection", projection);
		}
		else
		{
			projection = glm::perspective(glm::radians(viewingAngle), (win_width/(float)win_height), 0.1f, 100.0f);
			lightingShader->setMat4("projection", projection);

		}

		// Retrieve location of tranform variable in shader.	
 		//loc = glGetUniformLocation(program, "projection");
   		// Send matrix to shader.
		//glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(projection));
	}

	
	// Define view matrix.
	glm::vec3 camera = glm::vec3(0.0f,0.0f,-3.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), camera);	// Camera
	lightingShader->setMat4("view", view);

	
	// LIGHTING ------------------
    glBindVertexArray(VAO);
	
	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
	glm::vec3 objectColor(1.0f, 0.7f, 0.31f);
	glm::vec3 lightResult = lightColor * objectColor; // = (1.0f, 0.5f, 0.31f);

	lightingShader->use();
	lightingShader->setVec3("lightColor", lightColor);
	lightingShader->setVec3("objectColor", objectColor);
	lightingShader->setFloat("ambientAtenuation", 0.3f);
	lightingShader->setVec3("lightPosition", lightPos);  
	lightingShader->setVec3("viewPos", -camera); 	//camera



	modelP->Draw(*lightingShader, wireframeView);

	
	
	// LIGHT ------------------
	glBindVertexArray(lightVAO);

	glm::mat4 lightCubeModelMatrix = glm::mat4(1.0f);
	lightCubeModelMatrix = glm::translate(lightCubeModelMatrix, lightPos);
	lightCubeModelMatrix = glm::scale(lightCubeModelMatrix, glm::vec3(0.2f)); 
	lightCubeModelMatrix = lightCubeModelMatrix*Rz*Ry*Rx;

	lightCubeShader->use();
	// set the model, view and projection matrix uniforms
	// draw the light cube object
	lightCubeShader->setMat4("model", lightCubeModelMatrix);
	lightCubeShader->setMat4("view", view);
	lightCubeShader->setMat4("projection", projection);
	
	lightCube->Draw(*lightingShader, wireframeView);

	//glDrawArrays(GL_TRIANGLES, 0, 36);	


	//glUseProgram(program);

	/* unsigned int loc = glGetUniformLocation(program, "model");

	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(M)); */


	
	/* if(wireframeView) {
  		glDrawArrays(GL_LINE_LOOP, 0, 36);
	}
	else {
  		glDrawArrays(GL_TRIANGLES, 0, 36);
	} */

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

	glEnable(GL_DEPTH_TEST);
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


char* getModelPath(int argc, char **argv) {
	char* filepath;
	if(argc > 1){
		filepath = argv[1];
		logger->log(INFO, "Abrindo arquivo...");

	}
	else{
		filepath = DEFAULT_FILE_PATH;
		logger->log(ERROR, "Nenhum arquivo recebido! Carregando arquivo padrão...");

	}

	logger->log(INFO, filepath);

	FILE *f = fopen(filepath, "r");

	if(f == nullptr){
		logger->log(ERROR, "Não foi possível abrir o arquivo.");
		logger->log(ERROR, "Carregando arquivo padrão...");
		filepath = DEFAULT_FILE_PATH;
	}
	fclose(f);
	return filepath;
}



int main(int argc, char **argv) 
{
	logger->setLogLevel(DEBUG);
	//logger->log(DEBUG, "Hello, OpenGL! I'm debug.");
	//logger->log(ERROR, "Hello, OpenGL! I'm error.");

	char* filepath = getModelPath(argc, argv);
	
	

	setupGlut(&argc, argv);
	glewInit(); 

	Shader myShader("src/model_loading.vs", "src/lighting.fs");
	lightingShader = &myShader;

	Shader secondShader("src/model_loading.vs", "src/lightCubeShader.fs");
	lightCubeShader = &secondShader;

	Model modelLoaded(filepath);
	modelP = &modelLoaded;
	Model cubeModel(DEFAULT_FILE_PATH);
	lightCube = &cubeModel;

	initVAO();
    initShaders();
	registerCallbacks();
        	
	
	// enter GLUT event processing cycle
	glutMainLoop(); 
	//glutDestroyWindow(glutGetWindow());
	return 0;
}

