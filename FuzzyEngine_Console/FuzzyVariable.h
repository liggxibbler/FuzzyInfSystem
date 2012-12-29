#ifndef _FUZZY_VARIABLE_H_
#define _FUZZY_VARIABLE_H_

#include "FuzzyMemFunc.h"
#include <map>

namespace Fuzzy
{
	class Variable
	{
	public:
		Variable();
		Variable(Variable& other);
		~Variable();

		bool Initialize();
		void Shutdown();
		float IsIf(std::string function, float input); // return function(input)
		MemFunc* IsThen(std::string function, float value); // return MF clamped at

		int GetFuncCount();
		std::string GetID();

	private:
		std::string m_ID;
		int m_memFuncCount;
		MemFunc* m_memFuncs;
		std::map<std::string, MemFunc*> m_mapFunc;
	};
}
#endif