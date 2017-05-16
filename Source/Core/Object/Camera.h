/*
  ==============================================================================

    Camera.h
    Created: 14 May 2017 12:13:09pm
    Author:  Robin

  ==============================================================================
*/

#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "Transform.h"

class Camera : public Transformation
{
public:
	void Add_Rotation_X(float addRotation);
	void Add_Rotation_Y(float addRotation);
	void Add_Rotation_Z(float addRotation);

protected:

private:
};



#endif  // CAMERA_H_INCLUDED
