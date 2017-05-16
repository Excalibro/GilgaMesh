/*
  ==============================================================================

    Vector2D.cpp
    Created: 16 May 2017 12:25:19pm
    Author:  Robin

  ==============================================================================
*/

#include "Vector2D.h"

Vector2D::Vector2D()
{
	m_x = 0;
	m_y = 0;
	m_isValid = true;
}

Vector2D::Vector2D(float x, float y)
{
	m_x = x;
	m_y = y;
	m_isValid = true;
}

Vector2D::Vector2D(float x, float y, bool isValid)
{
	m_x = x;
	m_y = y;
	m_isValid = isValid;
}

Vector2D::~Vector2D()
{
}

bool Vector2D::Normalize()
{
	if (m_x != 0 || m_y != 0)
	{
		float length = Length();

		m_x = m_x / length;
		m_y = m_y / length;

		return true;
	}
	else
	{
		return false;
	}
}

float Vector2D::Length()
{
	return 	std::sqrt(m_x*m_x + m_y*m_y);
}
