/*
  ==============================================================================

    Vertex.cpp
    Created: 14 May 2017 11:56:40am
    Author:  Robin

  ==============================================================================
*/

#include "Vertex.h"



Vertex::Vertex()
{
}

Vertex::Vertex(float location_x, float location_y, float location_z)
{
	m_location_x = location_x;
	m_location_y = location_y;
	m_location_z = location_z;
}

Vertex::~Vertex()
{
}
