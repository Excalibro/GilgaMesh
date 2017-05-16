/*
  ==============================================================================

    Camera.cpp
    Created: 14 May 2017 12:13:09pm
    Author:  Robin

  ==============================================================================
*/

#include "Camera.h"

void Camera::Add_Rotation_X(float addRotation)
{
	m_rotation[0] += addRotation;
}

void Camera::Add_Rotation_Y(float addRotation)
{
	m_rotation[1] += addRotation;
}

void Camera::Add_Rotation_Z(float addRotation)
{
	m_rotation[2] += addRotation;
}
