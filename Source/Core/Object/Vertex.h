/*
  ==============================================================================

    Vertex.h
    Created: 14 May 2017 11:56:40am
    Author:  Robin

  ==============================================================================
*/

#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED


class Vertex
{
public:
	Vertex();
	Vertex(float location_x, float location_y, float location_z);
	~Vertex();

	float m_location_x;
	float m_location_y;
	float m_location_z;

protected:

private:

};


#endif  // VERTEX_H_INCLUDED
