#ifndef _FUZZY_VARIABLE_H_
#define _FUZZY_VARIABLE_H_

#include "FuzzyMemFunc.h"
#include <map>

class FuzzyVariable
{
public:
	FuzzyVariable();
	FuzzyVariable(FuzzyVariable& other);
	~FuzzyVariable();

	bool Initialize();
	void Shutdown();
	float Is(std::string function); // 
	float* Is(float value); // return points at which var is value

private:
	std::string m_ID;
	int m_memFuncCount;
	FuzzyMemFunc* m_memFuncs;
	std::map<std::string, FuzzyMemFunc*> m_mapFunc;
};

#endif