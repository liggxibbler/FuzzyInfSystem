#ifndef _FUZZY_INF_SYSTEM_H_
#define _FUZZY_INF_SYSTEM_H_

#include "FuzzyVariable.h"
#include <list>
#include <map>

namespace Fuzzy
{
	class InfSystem
	{
	private:
		struct Pair
		{
			std::string variable;
			std::string value;
		};

		struct Rule
		{
			Pair input1;
			Pair input2;
			Pair output;
		};
	
		//struct RuleBase
		//{
		//	RulePair* input;   // these could work for a more general system
		//	RulePair* output;  // with arbitrary input and outputs
		//};

	public:
		InfSystem();
		InfSystem(InfSystem& other);
		~InfSystem();

		bool Initialize(char* filename);
		void Shutdown();
		float Evaluate(float input1, float input2);
		
		void AddInputVariable(Variable** vars, int varCount);
		void AddOutputVariable(Variable** vars, int varCount);
		void AddRule(std::string var1, std::string val1, std::string var2, std::string val2,
			std::string out, std::string outVal); // for 2i/1o system

	private:
		MemFunc* Aggregate();

	private:
		std::map<std::string, Variable*> m_mapVar;
		std::list<Variable*> m_inputs;
		std::list<Variable*> m_outputs;
		MemFunc* m_thenPart;
		std::list<Rule*> m_ruleBase;
		int m_ruleCount;
		int m_inputCount;
		int m_outputCount;
	};
}
#endif