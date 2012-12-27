#ifndef _FUZZY_INF_SYSTEM_H_
#define _FUZZY_INF_SYSTEM_H_

#include "FuzzyVariable.h"

class FuzzyInfSystem
{
private:
	struct RuleTwoInOneOut
	{
		//std::pair<std::string, std::string>* input;   // these could work for a more general system
		//std::pair<std::string, std::string>* output;  // with arbitrary input and outputs
		std::string input1;
		std::string value1;
		std::string input2;
		std::string value2;
		std::string output;
		std::string outValue;
	};
public:
	FuzzyInfSystem();
	FuzzyInfSystem(FuzzyInfSystem& other);
	~FuzzyInfSystem();

	bool Initialize();
	void Shutdown();
	float Evaluate(float* input);

private:
	FuzzyVariable* m_inputs;
	FuzzyVariable* m_outputs;
	int m_ruleCount;
	RuleTwoInOneOut* m_ruleBase;
};

#endif