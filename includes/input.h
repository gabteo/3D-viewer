#ifndef INPUT_H
#define INPUT_H

#include "../includes/errorType.h"
#include "../includes/logging.h"
#include "../includes/gutils.h"



error_type_t setTransformMode(transform_type_t mode);
error_type_t toggleViewMode();


// letter keys
error_type_t transformKeyPress(unsigned char key);
error_type_t keyPressTranslation(unsigned char key);
error_type_t keyPressRotation(unsigned char key);
error_type_t keyPressScale(unsigned char key);

// arrow keys
void transformKeyPress(int key, int x, int y);
error_type_t keyPressTranslation(int key);
error_type_t keyPressRotation(int key);
error_type_t keyPressScale(int key);

void keyboard(unsigned char key, int x, int y);
//void keyboardArrows(int key, int x, int y);
void mouse(int button, int state, int x, int y);



#endif