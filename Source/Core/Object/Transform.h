/*
  ==============================================================================

    Transform.h
    Created: 14 May 2017 12:11:50pm
    Author:  Robin

  ==============================================================================
*/

#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED

class Transformation
{
public:

	float m_location[3];
	float m_rotation[3];
	float m_scale[3];

	Transformation();
	~Transformation();

protected:

private:

};



#endif  // TRANSFORM_H_INCLUDED
