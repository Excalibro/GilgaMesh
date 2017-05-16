/*
  ==============================================================================

    MatLib.cpp
    Created: 16 May 2017 12:08:14pm
    Author:  Robin

  ==============================================================================
*/

#include "MatLib.h"

Vector2D MatLib::Get_IntersectionPoint_2D(float vector_A_UpPoint_X, float vector_A_UpPoint_Y, float vector_A_Direction_X, float vector_A_Direction_Y, float vector_B_UpPoint_X, float vector_B_UpPoint_Y, float vector_B_Direction_X, float vector_B_Direction_Y)
{
	//Convertion from Parametric to Implicit form:

	// x + ny + b = 0 Vars:
	float n1;
	float b1;

	float n2;
	float b2;

	n1 = -1 / (vector_A_Direction_Y / vector_A_Direction_X);
	n2 = -1 / (vector_B_Direction_Y / vector_B_Direction_X);

	b1 = -(vector_A_UpPoint_Y - (vector_A_Direction_Y / vector_A_Direction_X) * vector_A_UpPoint_X) * n1;
	b2 = -(vector_B_UpPoint_Y - (vector_B_Direction_Y / vector_B_Direction_X) * vector_B_UpPoint_X) * n2;

	// Subtracting Term 2 from Term 1 (Resulting in Term 3 (ny + b = 0)):
	float n3;
	float b3;

	n3 = n1 - n2;
	b3 = b1 - b2;

	float xResult;
	float yResult;

	yResult = -b3 / n3;

	xResult = -(n1 * yResult) - b1;

	//SetupReturnPoint

	Vector2D returnPoint;
	returnPoint.m_x = xResult;
	returnPoint.m_y = yResult;

	if (n1 == n2)
	{

	}

	return returnPoint;

}

bool MatLib::Get_PointLiesInTriangle(float triPoint_A_X, float triPoint_A_Y, float triPoint_B_X, float triPoint_B_Y, float triPoint_C_X, float triPoint_C_Y, float point_X, float point_Y, bool includeEdgePoint)
{
	float a_x;
	float a_y;
	float b_x;
	float b_y;
	float c_x;
	float c_y;

	// Sort by X location:
	if (triPoint_A_X <= triPoint_B_X && triPoint_B_X <= triPoint_C_X)
	{
		a_x = triPoint_A_X;	a_y = triPoint_A_Y;
		b_x = triPoint_B_X;	b_y = triPoint_B_Y;
		c_x = triPoint_C_X;	c_y = triPoint_C_Y;
	}
	else if (triPoint_C_X <= triPoint_B_X && triPoint_B_X <= triPoint_A_X)
	{
		a_x = triPoint_C_X;	a_y = triPoint_C_Y;
		b_x = triPoint_B_X;	b_y = triPoint_B_Y;
		c_x = triPoint_A_X;	c_y = triPoint_A_Y;
	}
	else if (triPoint_B_X <= triPoint_A_X && triPoint_A_X <= triPoint_C_X)
	{
		a_x = triPoint_B_X;	a_y = triPoint_B_Y;
		b_x = triPoint_A_X;	b_y = triPoint_A_Y;
		c_x = triPoint_C_X;	c_y = triPoint_C_Y;
	}
	else if (triPoint_C_X <= triPoint_A_X && triPoint_A_X <= triPoint_B_X)
	{
		a_x = triPoint_C_X;	a_y = triPoint_C_Y;
		b_x = triPoint_A_X;	b_y = triPoint_A_Y;
		c_x = triPoint_B_X;	c_y = triPoint_B_Y;
	}
	else if (triPoint_A_X <= triPoint_C_X && triPoint_C_X <= triPoint_B_X)
	{
		a_x = triPoint_A_X;	a_y = triPoint_A_Y;
		b_x = triPoint_C_X;	b_y = triPoint_C_Y;
		c_x = triPoint_B_X;	c_y = triPoint_B_Y;
	}
	else
	{
		a_x = triPoint_B_X;	a_y = triPoint_B_Y;
		b_x = triPoint_C_X;	b_y = triPoint_C_Y;
		c_x = triPoint_A_X;	c_y = triPoint_A_Y;
	}

	// create functions parameters (y = mx + u):
	float ab_m = (b_y - a_y) / (b_x - a_x);
	float ab_u = a_y - (a_x * ab_m);

	float bc_m = (c_y - b_y) / (c_x - b_x);
	float bc_u = b_y - (b_x * bc_m);

	float ac_m = (c_y - a_y) / (c_x - a_x);
	float ac_u = a_y - (a_x * ac_m);


	// Switch algorythm on includeEdgePoint:
	if (includeEdgePoint)
	{
		// return false if Point is out of xRange:
		if (point_X < a_x || point_X > c_x)
		{
			return false;
		}

		// Check Y coordinates:
		if (point_X < b_x)
		{
			if (((point_Y <= ab_m*point_X + ab_u) && point_Y >= (ac_m*point_X + ac_u)) || (point_Y >= (ab_m*point_X + ab_u) && point_Y <= (ac_m*point_X + ac_u)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (((point_Y <= bc_m*point_X + bc_u) && point_Y >= (ac_m*point_X + ac_u)) || (point_Y >= (bc_m*point_X + bc_u) && point_Y <= (ac_m*point_X + ac_u)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		// return false if Point is out of xRange:
		if (point_X <= a_x || point_X >= c_x)
		{
			return false;
		}

		// Check Y coordinates:
		if (point_X < b_x)
		{
			if (((point_Y < ab_m*point_X + ab_u) && point_Y > (ac_m*point_X + ac_u)) || (point_Y > (ab_m*point_X + ab_u) && point_Y < (ac_m*point_X + ac_u)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (((point_Y < bc_m*point_X + bc_u) && point_Y > (ac_m*point_X + ac_u)) || (point_Y > (bc_m*point_X + bc_u) && point_Y < (ac_m*point_X + ac_u)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	}



	return false;
}

unsigned int MatLib::Get_RelativeVectorElement(unsigned int startElementId, int vectorSize, int steps)
{
	int Pointer = startElementId + steps;

	if (Pointer > vectorSize - 1)
	{
		Pointer = Pointer - ((Pointer / vectorSize) * vectorSize);
	}
	else if (Pointer < 0)
	{
		Pointer = Pointer + ((std::abs(Pointer + 1) / vectorSize + 1) * vectorSize);
	}

	return Pointer;

}