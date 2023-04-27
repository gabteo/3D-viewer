

#ifndef GUTILS_H
#define GUTILS_H

#define DEFAULT_FILE_PATH "obj/Cube obj/Cube obj.obj"

//screen
#define HD_WIN_WIDTH 1280
#define HD_WIN_HEIGH 720

#define WIN_WIDTH HD_WIN_WIDTH
#define WIN_HEIGH HD_WIN_HEIGH


static int win_width = WIN_WIDTH;
static int win_height = WIN_HEIGH;
static int window;


enum transform_type_t {
    TRANSLATION,
    ROTATION,
    SCALE
};

static transform_type_t transformMode = TRANSLATION;
extern bool faceView;
extern bool wireframeView;




extern float xPos;
extern float yPos;
extern float zPos;

extern float xScale;
extern float yScale;
extern float zScale;

extern float xRotation;
extern float yRotation;
extern float zRotation;

static const float posIncrement = 0.02f;
static const float scaleUpFactor = 1.1f;
static const float scaleDownFactor = 0.9f;
static const float rotationIncrement = 2.0f;

/**------------------------------------------------*/

/*-------------------------------------------*/

//Geometry
enum { X_AXIS, Y_AXIS, Z_AXIS };

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

typedef vector4 point4;
 
//utils
point normalizeClick(int x, int y);
float normalizeClickInAxis(int value, int axis, int win_width, int win_height);



#endif