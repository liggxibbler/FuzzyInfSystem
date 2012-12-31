#include "FuzzyInfSystem.h"

using namespace Fuzzy;

InfSystem::InfSystem()
{
	m_inputCount = 0;
	m_outputCount = 0;
	m_ruleCount = 0;
	
	m_thenPart = 0;
}

InfSystem::InfSystem(InfSystem& other)
{
}

InfSystem::~InfSystem()
{
}

void InfSystem::AddInputVariable(Variable** vars, int varCount)
{
	m_inputCount += varCount;
	for(int i=0; i< varCount; i++)
	{
		m_mapVar[vars[i]->GetID()] = vars[i];
		m_inputs.push_back(vars[i]);
	}
}

void InfSystem::AddOutputVariable(Variable** vars, int varCount)
{
	m_outputCount += varCount;
	for(int i=0; i< varCount; i++)
	{
		m_mapVar[vars[i]->GetID()] = vars[i];
		m_outputs.push_back(vars[i]);
	}
}

float InfSystem::Evaluate(float input1, float input2)
{
	// clear m_thenPart -> set all to zeros	

	// for every rule in rulebase:
	//   aggregate result with then part
	
	// defuzzify result
	return m_thenPart->Defuzzify();
}