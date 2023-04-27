#include "../includes/colors.h"

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

void setBackgroundColor(color color)
{
    glClearColor(color.r, color.g, color.b, 1.0);
    return;
}

color rgbToFloat(int r, int g, int b)
{
    color color;
    color.r = ((float)r)/255.0;
    color.g = ((float)g)/255.0;
    color.b = ((float)b)/255.0;

    return color;
}

