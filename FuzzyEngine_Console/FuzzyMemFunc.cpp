#include "FuzzyMemFunc.h"

FuzzyMemFunc::FuzzyMemFunc()
{
	m_dataPoints = 0;
}

FuzzyMemFunc::FuzzyMemFunc(FuzzyMemFunc& other)
{
}

FuzzyMemFunc::~FuzzyMemFunc()
{
}

bool FuzzyMemFunc::Initialize(std::string id, float min, float max, int pointCount)
{
	m_funcName = id;
	m_minRange = min;
	m_maxRange = max;
	m_pointCount = pointCount;
	
	MapInputToIndex();

	m_dataPoints = new float[m_pointCount];
	if(!m_dataPoints)
	{
		return false;
	}
	
	return true;
}

float FuzzyMemFunc::Evaluate(float input)
{
	float dx, delta, output;
	int index;

	dx = (m_maxRange - m_minRange) / m_pointCount;
	index = (input - m_minRange) / dx;
	delta = input - index * dx;
	if((index + 1) < m_pointCount) // avoid out of bounds errors
	{
		output = m_dataPoints[index] + delta * (m_dataPoints[index + 1] - m_dataPoints[index]) / dx;
	}
	else
	{
		output = 0;
	}

	return output;
}

void FuzzyMemFunc::Shutdown()
{
	if(m_dataPoints)
	{
		delete [] m_dataPoints;
		m_dataPoints = 0;
	}
}