#ifndef _FUZZY_MEMBERSHIP_FUNCTION_H_
#define _FUZZY_MEMBERSHIP_FUNCTION_H_

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

		bool Initialize(std::string id, float min, float max, int pointCount, float left, float mid, float right);
		void LoadTriangle(float left, float mid, float right);
		void Shutdown();
		float operator () (float input);
		float Defuzzify();

		float GetX(int index);
		float GetY(int index);
		int GetPointCount();

	private:
		float Evaluate(float input);
	private:
		int m_pointCount;
		float m_maxRange;
		float m_minRange;
		float* m_dataPointsX;
		float* m_dataPointsY;
		std::string m_funcName;
	};
}
#endif