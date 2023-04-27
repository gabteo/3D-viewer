#include "../includes/input.h"
#include "../includes/gutils.h"
#include "../includes/errorType.h"
#include "../includes/logging.h"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <iostream>
using namespace std;

logging* logger = logging::getInstance();

/* extern float xPos;
extern float yPos;
extern float zPos;

extern float xScale;
extern float yScale;
extern float zScale;

extern float xRotation;
extern float yRotation;
extern float zRotation; */

 float xPos = 0.0f;
 float yPos = 0.0f;
 float zPos = 0.0f;

 float xScale = 1.0f;
 float yScale = 1.0f;
 float zScale = 1.0f;

 float xRotation = 0.0f;
 float yRotation = 0.0f;
 float zRotation = 0.0f;

 bool faceView = true;
 bool wireframeView = !faceView;

error_type_t setTransformMode(transform_type_t mode)
{
    transformMode = mode;
    return Success;
}

error_type_t toggleViewMode()
{
    faceView = !faceView;
    wireframeView = !faceView;
    return Success;
}



void keyboard(unsigned char key, int x, int y)
{


    switch (key)
    {
        case 't':
        {
            logger->log(INFO, "Entering TRANSLATION mode.");
            setTransformMode(TRANSLATION);
            break;
        }
        case 'r':
        {
            logger->log(INFO, "Entering ROTATION mode.");
            setTransformMode(ROTATION);
            break;
        }
        case 'e':
        {  
            logger->log(INFO, "Entering SCALE mode.");
            setTransformMode(SCALE);
            break;
        }
        case 'v':
        {
            logger->log(INFO, "Toggling VIEW mode.");
            toggleViewMode();
            break;
        }
        case 27: //esc
        case 'q':
        case 'Q':
            /* glDeleteTextures();
            glDeleteBuffers(); */
            logger->log(INFO, "Exiting program...");

            glutDestroyWindow(glutGetWindow());
            glutLeaveMainLoop();

            break;
        default:
        {
            transformKeyPress(key);
            break;
        }
    }
	glutPostRedisplay();
}

error_type_t transformKeyPress(unsigned char key)
{
    switch (transformMode)
    {
    case TRANSLATION:
    {
        keyPressTranslation(key);
        cout << "x: " << xPos << " y: " << yPos << " z: "<< zPos << endl;

        break;
    }
    case ROTATION:
    {
        keyPressRotation(key);
        break;
    }
    case SCALE:
    {
        keyPressScale(key);
        break;
    }
    
    default:
        break;
    }

    return Success;
}

void transformKeyPress(int key, int x, int y)
{
    logger->log(DEBUG, "Arrow key pressed!");

    switch (transformMode)
    {
    case TRANSLATION:
    {
        keyPressTranslation(key);
        cout << "x: " << xPos << " y: " << yPos << " z: "<< zPos << endl;

        break;
    }
    case ROTATION:
    {
        keyPressRotation(key);
        break;
    }
    case SCALE:
    {
        keyPressScale(key);
        break;
    }
    
    default:
        break;
    }
	glutPostRedisplay();
}

error_type_t keyPressTranslation(unsigned char key)
{
    switch (key)
    {
    case 'a':
    {
        zPos += posIncrement;
        logger->log(INFO, "TRANSLAÇÃO +z");
        break;
    }
    case 'd':
    {
        zPos -= posIncrement;
        logger->log(INFO, "TRANSLAÇÃO -z");
        break;
    }
    
    default:
        break;
    }

    // TODO
    // print position
}

error_type_t keyPressTranslation(int key)
{
    logger->log(DEBUG, "Arrow: TRANSLATION");
    cout << key << endl;
    switch (key)
    {
    case GLUT_KEY_UP:
    {
        yPos += posIncrement;

        logger->log(INFO, "TRANSLAÇÃO +y");
        break;
    }
    case GLUT_KEY_DOWN:
    {
        yPos -= posIncrement;
        logger->log(INFO, "TRANSLAÇÃO -y");
        break;
    }
    case GLUT_KEY_LEFT:
    {
        xPos -= posIncrement;
        logger->log(INFO, "TRANSLAÇÃO -x");
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        xPos += posIncrement;
        logger->log(INFO, "TRANSLAÇÃO +x");
        break;
    }    
    default:
        break;
    }

    // TODO
    // print position
}

error_type_t keyPressRotation(unsigned char key)
{
    switch (key)
    {
    case 'a':
    {
        zRotation += rotationIncrement;
        logger->log(INFO, "ROTAÇÃO +Z");
        break;
    }
    case 'd':
    {
        zRotation -= rotationIncrement;
        logger->log(INFO, "ROTAÇÃO -Z");
        break;
    }
    
    default:
        break;
    }
}

error_type_t keyPressRotation(int key)
{
    switch (key)
    {
    case GLUT_KEY_UP:
    {
        xRotation += rotationIncrement;
        logger->log(INFO, "ROTAÇÃO +X");
        break;
    }
    case GLUT_KEY_DOWN:
    {
        xRotation -= rotationIncrement;

        logger->log(INFO, "ROTAÇÃO -X");
        break;
    }
    case GLUT_KEY_LEFT:
    {
        yRotation -= rotationIncrement;
        logger->log(INFO, "ROTAÇÃO -Y");
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        yRotation += rotationIncrement;
        logger->log(INFO, "ROTAÇÃO +Y");
        break;
    }
    
    default:
        break;
    }
}

error_type_t keyPressScale(unsigned char key)
{
    logger->log(DEBUG, "Z scale not implemented.");
    switch (key)
    {
    case 'a':
    {
        logger->log(INFO, "ESCALA +Z");
        break;
    }
    case 'd':
    {
        logger->log(INFO, "ESCALA -Z");
        break;
    }
    
    default:
        break;
    }
    return Success;
}

error_type_t keyPressScale(int key)
{
    switch (key)
    {
    case GLUT_KEY_UP:
    {
        yScale *= scaleUpFactor;
        logger->log(INFO, "ESCALA +Y");
        break;
    }
    case GLUT_KEY_DOWN:
    {
        yScale *= scaleDownFactor;
        logger->log(INFO, "ESCALA -Y");
        break;
    }
    case GLUT_KEY_LEFT:
    {
        xScale *= scaleDownFactor;
        logger->log(INFO, "ESCALA -X");
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        xScale *= scaleUpFactor;
        logger->log(INFO, "ESCALA +X");
        break;
    }
    
    default:
        break;
    }
    return Success;
}


void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN){
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            break;

        default:
            break;
        }
    }
	//glutPostRedisplay();

}

