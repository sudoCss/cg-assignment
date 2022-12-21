#ifndef _CAMERA_H
#define _CAMERA_H

#include "Includes.h"

#define PI 3.141592653589
#define PIdiv180 (PI / 180.0)

struct Vector3dStruct
{
    GLfloat x, y, z;
};
Vector3dStruct Vector3dCreate(GLfloat x, GLfloat y, GLfloat z);
Vector3dStruct NormalizeVector3d(Vector3dStruct v);
class Camera
{
public:
    Vector3dStruct View;
    Vector3dStruct RightVector;
    Vector3dStruct LeftVector;
    Vector3dStruct Up;
    Vector3dStruct Down;
    Vector3dStruct Position;

    GLfloat RotatedX, RotatedY, RotatedZ;

public:
    Camera();          // inits the values (Position: (0|0|0) Target: (0|0|-1) )
    void render(void); // executes some glRotates and a glTranslate command
                       // Note: You should call glLoadIdentity before using Render

    void Move(Vector3dStruct Direction);
    void RotateX(GLfloat Angle);
    void RotateY(GLfloat Angle);
    void RotateZ(GLfloat Angle);

    void MoveForward(GLfloat Distance);
    void MoveBackward(GLfloat Distance);
    void MoveUpward(GLfloat Distance);
    void MoveDownward(GLfloat Distance);
    void MoveRight(GLfloat Distance);
    void MoveLeft(GLfloat Distance);

    void SetRotateX(GLfloat Angle);
};

#endif