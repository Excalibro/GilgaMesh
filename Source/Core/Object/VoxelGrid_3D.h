/*
  ==============================================================================

    VoxelGrid_3D.h
    Created: 14 May 2017 11:56:31am
    Author:  Robin

  ==============================================================================
*/

#ifndef VOXELGRID_3D_H_INCLUDED
#define VOXELGRID_3D_H_INCLUDED

#include <Vector>

#include "Mesh.h"
#include "Voxel.h"
#include "Vertex.h"
#include "PolyObject.h"

class VoxelGrid_3D : public Mesh, public PolyObject
{
public:

	VoxelGrid_3D();
	VoxelGrid_3D(int size[3]);
	~VoxelGrid_3D();

	Voxel* Get_Voxel(int position_x, int position_y, int position_z);
	Vertex* Get_Vertex(int position_x, int position_y, int position_z);

protected:

	std::vector<Voxel> m_grid;
	std::vector<Vertex> m_gridVertices;
	float m_gridSize[3];

	void Initialize_VoxelGrid();
	void Generate_PolyMesh();


private:
};



#endif  // VOXELGRID_3D_H_INCLUDED
