#ifndef HANDLERS_INPUT_H
#define HANDLERS_INPUT_H

/** 
 * Keyboard function.
 *
 * Called to treat pressed keys.
 *
 * @param key Pressed key.
 * @param x Mouse x coordinate when key pressed.
 * @param y Mouse y coordinate when key pressed.
 */
void keyboard(unsigned char key, int x, int y);


/** 
 * Mouse function.
 *
 * Called to treat pressed buttons on the mouse.
 *
 * @param button Pressed button.
 * @param x Mouse x coordinate when key pressed.
 * @param y Mouse y coordinate when key pressed.
 * @param state GLUT_DOWN or GLUT_UP.
 * 
 */
void mouse(int button, int state, int x, int y);

#endif