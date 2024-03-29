#include "FuzzyMemFunc.h"

using namespace Fuzzy;

MemFunc::MemFunc()
{
	m_dataPointsX = 0;
	m_dataPointsY = 0;
}

MemFunc::MemFunc(MemFunc& other)
{
}

MemFunc::~MemFunc()
{
}

bool MemFunc::Initialize(std::string id, float min, float max, int pointCount)
{
	m_funcName = id;
	m_minRange = min;
	m_maxRange = max;
	m_pointCount = pointCount;
	
	m_dataPointsY = new float[m_pointCount];
	if(!m_dataPointsY)
	{
		return false;
	}
	for(int i=0; i<m_pointCount; i++)
	{
		m_dataPointsY[i] = 0;
	}

	m_dataPointsX = new float[m_pointCount];
	if(!m_dataPointsX)
	{
		return false;
	}
	for(int i=0; i<m_pointCount; i++)
	{
		m_dataPointsX[i] = 0;
	}

	for(int i=0; i<m_pointCount;i++)
	{
		m_dataPointsX[i] = m_minRange + i * (m_maxRange - m_minRange)/(m_pointCount - 1);
	}

	return true;
}

float MemFunc::Evaluate(float input)
{
	float dx, delta, output;
	int index;

	dx = (m_maxRange - m_minRange) / (m_pointCount-1);
	index = floor((input - m_minRange) / (m_pointCount - 1));
	delta = input - m_dataPointsX[index];
	if( ((index + 1) < m_pointCount) && (index >= 0) ) // avoid out of bounds errors
	{
		output = m_dataPointsY[index] + delta * (m_dataPointsY[index + 1] - m_dataPointsY[index]);
	}
	else
	{
		output = 0;
	}

	return output;
}

void MemFunc::Shutdown()
{
	if(m_dataPointsY)
	{
		delete [] m_dataPointsY;
		m_dataPointsY = 0;
	}

	if(m_dataPointsX)
	{
		delete [] m_dataPointsX;
		m_dataPointsX = 0;
	}
}

float MemFunc::operator() (float input)
{
	return Evaluate(input);
}

float MemFunc::Defuzzify()
{
	// for now, use easy way: centroid
	float numerator, denominator;

	numerator = 0;
	denominator = 0;
	for(int i=0; i<m_pointCount; i++)
	{
		numerator += m_dataPointsY[i] * m_dataPointsX[i];
		denominator += m_dataPointsX[i];
	}

	return numerator / denominator;
}

MemFunc* MemFunc::Clamp(float limit)
{
	MemFunc* result = new MemFunc;
	result->Initialize(m_funcName + "_clamped", m_minRange, m_maxRange, m_pointCount);
	for(int i=0; i<m_pointCount; i++)
	{
		if(m_dataPointsY[i] > limit)
		{
			result->m_dataPointsY[i] = limit;
		}
		else
		{
			result->m_dataPointsY[i] = m_dataPointsY[i];
		}
	}
	return result;
}

float MemFunc::GetX(int index)
{
	return m_dataPointsX[index];
}

float MemFunc::GetY(int index)
{
	return m_dataPointsY[index];
}

int MemFunc::GetPointCount()
{
	return m_pointCount;
}

std::string MemFunc::GetName()
{
	return m_funcName;
}

MemFunc* MemFunc::Imply(float premise)
{
	return this->Clamp(premise);
}

void MemFunc::Clear()
{
	if(m_dataPointsY)
	{
		for(int i=0;i<m_pointCount; i++)
		{
			m_dataPointsY[i] = 0;
		}
	}
}