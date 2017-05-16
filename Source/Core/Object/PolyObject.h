/*
  ==============================================================================

    PolyObject.h
    Created: 14 May 2017 3:23:44pm
    Author:  Robin

  ==============================================================================
*/

#ifndef POLYOBJECT_H_INCLUDED
#define POLYOBJECT_H_INCLUDED

#include<vector>

#include "NGon.h"
#include "Vertex.h"

class PolyObject
{
public:


	std::vector<Vertex> Vertices;
	std::vector<NGon> NGons;

protected:

private:
};



#endif  // POLYOBJECT_H_INCLUDED
