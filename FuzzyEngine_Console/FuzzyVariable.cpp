#include "FuzzyVariable.h"

using namespace Fuzzy;

Variable::Variable()
{
	m_memFuncCount = 0;
}

Variable::Variable(Variable& other)
{
}

Variable::~Variable()
{
}

void Variable::AddMemFunc(MemFunc** funcs, int mfCount)
{
	m_memFuncCount += mfCount;
	for(int i=0; i<mfCount; i++)
	{
		m_memFuncs.push_back(funcs[i]);
		m_mapFunc[funcs[i]->GetName()] = funcs[i];
	}
	return;
}

void Variable::Shutdown()
{
	std::list<MemFunc*>::iterator iter;
	for(iter = m_memFuncs.begin(); iter != m_memFuncs.end(); iter++)
	{
		delete *iter;
	}
}

float Variable::IsIf(std::string funcName, float input)
{
	MemFunc* function = m_mapFunc[funcName];
	return function->Evaluate(input);
}

MemFunc* Variable::IsThen(std::string funcName, float value)
{
	MemFunc* memFunc, *result;
	memFunc = m_mapFunc[funcName];
	result = memFunc->Imply(value);
	return result;
}

std::string Variable::GetID()
{
	return m_ID;
}