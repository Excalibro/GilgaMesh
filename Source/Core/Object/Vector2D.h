/*
  ==============================================================================

    Vector2D.h
    Created: 16 May 2017 12:25:19pm
    Author:  Robin

  ==============================================================================
*/

#ifndef VECTOR2D_H_INCLUDED
#define VECTOR2D_H_INCLUDED

#include <cmath>

class Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	Vector2D(float x, float y, bool isValid);

	~Vector2D();

	bool Normalize();
	float Length();

	float m_x;
	float m_y;
	bool m_isValid;

protected:

private:

};



#endif  // VECTOR2D_H_INCLUDED
