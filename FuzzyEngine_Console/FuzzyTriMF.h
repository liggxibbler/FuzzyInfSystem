#ifndef _FUZZY_TRI_MF_H_
#define _FUZZY_TRI_MF_H_

#include "FuzzyMemFunc.h"

namespace Fuzzy
{
	class TriMF : public MemFunc
	{
	public:

		TriMF();
		TriMF(TriMF& other);
		~TriMF();

		void Initialize(std::string name, float min, float max, int pointCount, float left, float mid, float right);
		void LoadTriangle(float left, float mid, float right);
	};
}

#endif