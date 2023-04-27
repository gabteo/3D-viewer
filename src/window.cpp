#include "../includes/gutils.h"
#include "../includes/window.h"
#include "../includes/shadersUtils.h"
#include "../includes/colors.h"

#include <iostream>
using namespace std;

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

void reshape(int width, int height)
{
    win_width = width;
    win_height = height;
    glViewport(0, 0, width, height);
    glutPostRedisplay();
	//renderScene();
}
