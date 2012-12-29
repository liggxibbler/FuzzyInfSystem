#include "FuzzyInfSystem.h"
#include <iostream>

using namespace std;

int main()
{
	Fuzzy::MemFunc mf;
	
	mf.Initialize("name", 3.2, 5.6, 9, 3.1, 3.2, 5.6);

	for(int i=0; i<mf.GetPointCount(); i++)
	{
		cout << mf.GetY(i) << ", ";
	}
	cout << endl;
	for(int i=0; i<mf.GetPointCount(); i++)
	{
		cout << mf.GetX(i) << ", ";
	}
	cout << endl;

	return 0;
}