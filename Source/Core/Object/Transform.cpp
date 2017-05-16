/*
  ==============================================================================

    Transform.cpp
    Created: 14 May 2017 12:11:50pm
    Author:  Robin

  ==============================================================================
*/

#include "Transform.h"

Transformation::Transformation()
{
	float m_location [3] = {0.0f,0.0f,0.0f};
	float m_rotation[3] = { 0.0f,0.0f,0.0f };
	float m_scale[3] = { 1.0f,1.0f,1.0f };
}

Transformation::~Transformation()
{
}
