

#ifndef GUTILS_H
#define GUTILS_H

#define DEFAULT_FILE_PATH "resource/Cube.obj"
#define DEFAULT_NORMAL_MAP_PATH "resource/txt/stool_2K_Normal_LOD0.jpg"
#define DEFAULT_TEXTURE_PATH "resource/txt/stool_2K_Albedo.jpg"
#define DEFAULT_VERTEX_SHADER_PATH "src/model_loading.vs"
#define DEFAULT_FRAGMENT_SHADER_PATH "src/model_loading.fs"
//screen
#define HD_WIN_WIDTH 1280
#define HD_WIN_HEIGH 1280

#define WIN_WIDTH HD_WIN_WIDTH
#define WIN_HEIGH HD_WIN_HEIGH


static int win_width = WIN_WIDTH;
static int win_height = WIN_HEIGH;
static int window;


enum transform_type_t {
    TRANSLATION,
    ROTATION,
    SCALE,
    CAMERA
};

static transform_type_t transformMode = TRANSLATION;
extern bool faceView;
extern bool wireframeView;
extern bool ortho;




extern float xPos;
extern float yPos;
extern float zPos;

extern float xScale;
extern float yScale;
extern float zScale;

extern float xRotation;
extern float yRotation;
extern float zRotation;

extern float viewingAngle;

static const float posIncrement = 0.02f;
static const float scaleUpFactor = 1.1f;
static const float scaleDownFactor = 0.9f;
static const float rotationIncrement = 2.0f;
static const float viewingAngleIncrement = 5.0f;

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