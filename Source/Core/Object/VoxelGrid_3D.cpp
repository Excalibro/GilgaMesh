/*
  ==============================================================================

    VoxelGrid_3D.cpp
    Created: 14 May 2017 11:56:31am
    Author:  Robin

  ==============================================================================
*/

#include "VoxelGrid_3D.h"

VoxelGrid_3D::VoxelGrid_3D()
  {
	  m_gridSize[0] = 50;
	  m_gridSize[1] = 50;
	  m_gridSize[2] = 50;

	  Initialize_VoxelGrid();
  }

  VoxelGrid_3D::VoxelGrid_3D(int size[3])
  {
	  m_gridSize[0] = (size[0] < 1 ? 1 : size[0]);
	  m_gridSize[1] = (size[1] < 1 ? 1 : size[1]);
	  m_gridSize[2] = (size[2] < 1 ? 1 : size[2]);

	  Initialize_VoxelGrid();
  }

  VoxelGrid_3D::~VoxelGrid_3D()
  {
  }

  Voxel * VoxelGrid_3D::Get_Voxel(int position_x, int position_y, int position_z)
  {
	  int position_x_fixed;
	  int position_y_fixed;
	  int position_z_fixed;

	  Voxel* returnVoxel;

	  /*Fix input:*/
	  //X:
	  if (position_x >= m_gridSize[0])
	  {
		  position_x_fixed = m_gridSize[0] - 1;
	  }
	  else if (position_x < 0)
	  {
		  position_x_fixed = 0;
	  }
	  else
	  {
		  position_x_fixed = position_x;
	  }
	  //Y:
	  if (position_y >= m_gridSize[1])
	  {
		  position_y_fixed = m_gridSize[1] - 1;
	  }
	  else if (position_y < 0)
	  {
		  position_y_fixed = 0;
	  }
	  else
	  {
		  position_y_fixed = position_y;
	  }
	  //Z:
	  if (position_z >= m_gridSize[2])
	  {
		  position_z_fixed = m_gridSize[2] - 1;
	  }
	  else if (position_z < 0)
	  {
		  position_z_fixed = 0;
	  }
	  else
	  {
		  position_z_fixed = position_z;
	  }

	  // Get return Voxel:
	  returnVoxel = &m_grid[
		  position_x_fixed +
		(position_y_fixed * m_gridSize[0]) +
		(position_z_fixed * (m_gridSize[0]* m_gridSize[1]))
	  ];

	  return returnVoxel;
  }

  Vertex* VoxelGrid_3D::Get_Vertex(int position_x, int position_y, int position_z)
  {
	  int position_x_fixed;
	  int position_y_fixed;
	  int position_z_fixed;

	  Vertex* returnVertex;

	  /*Fix input:*/
	  //X:
	  if (position_x > m_gridSize[0])
	  {
		  position_x_fixed = m_gridSize[0];
	  }
	  else if (position_x < 0)
	  {
		  position_x_fixed = 0;
	  }
	  else
	  {
		  position_x_fixed = position_x;
	  }
	  //Y:
	  if (position_y > m_gridSize[1])
	  {
		  position_y_fixed = m_gridSize[1];
	  }
	  else if (position_y < 0)
	  {
		  position_y_fixed = 0;
	  }
	  else
	  {
		  position_y_fixed = position_y;
	  }
	  //Z:
	  if (position_z > m_gridSize[2])
	  {
		  position_z_fixed = m_gridSize[2];
	  }
	  else if (position_z < 0)
	  {
		  position_z_fixed = 0;
	  }
	  else
	  {
		  position_z_fixed = position_z;
	  }

	  // Get return Voxel:
	  returnVertex = &m_gridVertices[
		  position_x_fixed +
			  (position_y_fixed * m_gridSize[0]) +
			  (position_z_fixed * (m_gridSize[0] * m_gridSize[1]))
	  ];

	  return returnVertex;
  }

  void VoxelGrid_3D::Initialize_VoxelGrid()
  {
	  //Setup Voxels and Vertices:
	  int numVoxels = m_gridSize[0] * m_gridSize[1] * m_gridSize[2];
	  int numVertices = m_gridSize[0]+1 * m_gridSize[1]+1 * m_gridSize[2]+1;

	  for (int i = 0; i < numVoxels; i++)
	  {
		  m_grid.push_back(Voxel());
	  }

	  for (int i = 0; i < numVertices; i++)
	  {
		  m_gridVertices.push_back(Vertex());
	  }

  }

  void VoxelGrid_3D::Generate_PolyMesh()
  {
	  NGons.clear();
	  // Generate New NGon data:
	  for (int x = 0; x < m_gridSize[0]; x++)
	  {
		  for (int y = 0; y < m_gridSize[1]; y++)
		  {
			for (int z = 0; y < m_gridSize[2]; z++)
			{
				if (Get_Voxel(x, y, z)->m_active)
				{
					bool fill_x_pos = false;
					bool fill_x_neg = false;
					bool fill_y_pos = false;
					bool fill_y_neg = false;
					bool fill_z_pos = false;
					bool fill_z_neg = false;

					//Setup fill bools:
					//xPos
					if (x = 0)
					{
						fill_x_neg = true;
					}
					else
					{
						if (!Get_Voxel(x - 1, y, z)->m_active)
						{
							fill_x_neg = true;
						}
					}
					//xNeg
					if (x = m_gridSize[0] - 1)
					{
						fill_x_pos = true;
					}
					else
					{
						if (!Get_Voxel(x + 1, y, z)->m_active)
						{
							fill_x_pos = true;
						}
					}
					//yPos
					if (y = 0)
					{
						fill_y_neg = true;
					}
					else
					{
						if (!Get_Voxel(x, y - 1, z)->m_active)
						{
							fill_y_neg = true;
						}
					}
					//yNeg
					if (x = m_gridSize[1] - 1)
					{
						fill_y_pos = true;
					}
					else
					{
						if (!Get_Voxel(x, y + 1, z)->m_active)
						{
							fill_y_pos = true;
						}
					}
					//zPos
					if (z = 0)
					{
						fill_y_neg = true;
					}
					else
					{
						if (!Get_Voxel(x, y, z - 1)->m_active)
						{
							fill_z_neg = true;
						}
					}
					//zNeg
					if (z = m_gridSize[2] - 1)
					{
						fill_z_pos = true;
					}
					else
					{
						if (!Get_Voxel(x, y, z + 1)->m_active)
						{
							fill_y_pos = true;
						}
					}

					//Create polygons
						// X Negative:
					if (fill_x_neg)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x,y,z));
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z));
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x, y , z + 1));
						NGons.push_back(newNGon);
					}

					if (fill_x_pos)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z + 1));
						NGons.push_back(newNGon);
					}

					if (fill_y_neg)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x, y, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x, y, z + 1));
						NGons.push_back(newNGon);
					}

					if (fill_y_pos)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z + 1));
						NGons.push_back(newNGon);
					}


					if (fill_z_neg)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x, y, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z));
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z));
						NGons.push_back(newNGon);
					}

					if (fill_z_pos)
					{
						NGon newNGon;
						newNGon.Vertices.push_back(Get_Vertex(x, y, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x + 1, y + 1, z + 1));
						newNGon.Vertices.push_back(Get_Vertex(x, y + 1, z + 1));
						NGons.push_back(newNGon);
					}

				}			
			}
		  }
	  }
  }
