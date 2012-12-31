#include "FuzzyTriMF.h"

using namespace Fuzzy;

TriMF::TriMF()
{
}

TriMF::TriMF(TriMF& other)
{
}

TriMF::~TriMF()
{
}

void TriMF::Initialize(std::string name, float min, float max, int pointCount, float left, float mid, float right)
{
	MemFunc::Initialize(name, min, max, pointCount);
	LoadTriangle(left, mid, right);
}

void TriMF::LoadTriangle(float left, float mid, float right)
{
	float x;

	for(int i=0; i<m_pointCount; i++)
	{
		x = m_dataPointsX[i]; 
		if(x <= left)
		{
			m_dataPointsY[i] = 0;
		}
		else if(x <= mid)
		{
			m_dataPointsY[i] = 1/(mid-left) * (x - left);
		}
		else if(x <= right)
		{
			m_dataPointsY[i] = -1/(right-mid) * (x - mid) + 1;
		}
		else
		{
			m_dataPointsY[i] = 0;
		}
	}
}

