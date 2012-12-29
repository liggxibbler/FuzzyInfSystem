#ifndef _FUZZY_INF_SYSTEM_H_
#define _FUZZY_INF_SYSTEM_H_

#include "FuzzyVariable.h"

namespace Fuzzy
{
	class InfSystem
	{
	private:
		struct RulePair
		{
			std::string variable;
			std::string value;
		};
		
		//struct RuleBase
		//{
		//	RulePair* input;   // these could work for a more general system
		//	RulePair* output;  // with arbitrary input and outputs
		//};

		struct Rule
		{
			RulePair input1;
			RulePair input2;
			RulePair output;
		};
	
	public:
		InfSystem();
		InfSystem(InfSystem& other);
		~InfSystem();

		bool Initialize(char* filename);
		void Shutdown();
		float Evaluate(float* input);
	
	private:
		MemFunc* Aggregate();

	private:
		Variable* m_inputs;
		Variable* m_outputs;
		MemFunc* m_thenParts;
		int m_ruleCount;
		Rule* m_ruleBase;
	};
}
#endif