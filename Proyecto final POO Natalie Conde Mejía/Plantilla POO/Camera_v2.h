//***************************************************************************
//
// Advanced CodeColony Camera
// Philipp Crocoll, 2003
//
//***************************************************************************

#ifndef _CAMERA_H_
#define _CAMERA_H_

#define PI 3.1415926535897932384626433832795
#define PIdiv180 (PI/180.0)

#include "GraphicsHelper.h"
/////////////////////////////////
//Note: All angles in degrees  //
/////////////////////////////////

struct SF3dVector  //Float 3d-vect, normally used
{
	float x,y,z;
};
struct SF2dVector
{
	float x,y;
};
SF3dVector F3dVector ( float x, float y, float z );

class Camera
{
private:
	
	SF3dVector ViewDir;
	SF3dVector RightVector;	
	SF3dVector UpVector;
	
	float RotatedX, RotatedY, RotatedZ;

	SF3dVector ViewPoint;
	SF3dVector Position;
	void Move ( SF3dVector Direction );
public:
	Camera();				//inits the values (Position: (0|0|0) Target: (0|0|-1) )
	void Update ( void );	//executes some glRotates and a glTranslate command
							//Note: You should call glLoadIdentity before using Update

	void RotateX ( float Angle );
	void RotateY ( float Angle );
	void RotateZ ( float Angle );

	void MoveForward ( float Distance );
	void MoveUpward ( float Distance );
	void StrafeRight ( float Distance );
	void SetAltitudPosition ( float altitud );
	Vector3 GetPosition();
};
#endif