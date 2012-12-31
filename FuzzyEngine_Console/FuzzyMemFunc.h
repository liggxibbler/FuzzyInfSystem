#ifndef _FUZZY_MEMBERSHIP_FUNCTION_H_
#define _FUZZY_MEMBERSHIP_FUNCTION_H_

#include <math.h>
#include <string>
#include <map>

namespace Fuzzy
{
	class MemFunc
	{
	public:
		MemFunc();
		MemFunc(MemFunc& other);
		~MemFunc();

		bool Initialize(std::string id, float min, float max, int pointCount);
		void Shutdown();
		float operator () (float input);
		float Defuzzify();
		MemFunc* Imply(float premise);

		float GetX(int index);
		float GetY(int index);
		int GetPointCount();
		std::string GetName();
		float Evaluate(float input);
		void Clear();

	private:
		MemFunc* Clamp(float limit);
		//MemFunc* Modulate(float factor);
	protected:
		int m_pointCount;
		float m_maxRange;
		float m_minRange;
		float* m_dataPointsX;
		float* m_dataPointsY;
		std::string m_funcName;
	};
}
#endif