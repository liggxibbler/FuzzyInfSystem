#ifndef _FUZZY_MEMBERSHIP_FUNCTION_H_
#define _FUZZY_MEMBERSHIP_FUNCTION_H_

#include <string>
#include <map>

class FuzzyMemFunc
{
public:
	FuzzyMemFunc();
	FuzzyMemFunc(FuzzyMemFunc& other);
	~FuzzyMemFunc();

	bool Initialize(std::string id, float min, float max, int pointCount);
	void Shutdown();
	void Evaluate(float input);

private:
	void MapInputToIndex();
private:
	int m_pointCount;
	float m_maxRange;
	float m_minRange;
	float* m_dataPoints;
	std::string m_funcName;
	std::map<float, int> m_mapInput2Index;
};

#endif