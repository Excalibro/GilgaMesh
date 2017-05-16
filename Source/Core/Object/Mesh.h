/*
  ==============================================================================

    Mesh.h
    Created: 14 May 2017 11:58:40am
    Author:  Robin

  ==============================================================================
*/

#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>

#include "Transform.h"
#include "Triangle.h"

class Mesh : public Transformation
{
public:

	std::vector<Triangle> Triangles;

private:

protected:

};


#endif  // MESH_H_INCLUDED
