/*
  ==============================================================================

    MatLib.h
    Created: 16 May 2017 12:08:14pm
    Author:  Robin

  ==============================================================================
*/

#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#include "../Object/Vector2D.h"

class MatLib
{
	/*Calculates the Intersectionpoint of two 2D Vectors*/
	static Vector2D Get_IntersectionPoint_2D(float vector_A_UpPoint_X,
		float vector_A_UpPoint_Y,
		float vector_A_Direction_X,
		float vector_A_Direction_Y,
		float vector_B_UpPoint_X,
		float vector_B_UpPoint_Y,
		float vector_B_Direction_X,
		float vector_B_Direction_Y);

	static bool Get_PointLiesInTriangle(float triPoint_A_X, float triPoint_A_Y,
		float triPoint_B_X, float triPoint_B_Y,
		float triPoint_C_X, float triPoint_C_Y,
		float point_X, float point_Y,
		bool includeEdgePoint);

	static unsigned int Get_RelativeVectorElement(unsigned int startElementId, int vectorSize, int steps);
};



#endif  // MATLIB_H_INCLUDED
