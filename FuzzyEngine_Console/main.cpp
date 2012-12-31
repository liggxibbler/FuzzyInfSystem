#include "FuzzyInfSystem.h"
#include "FuzzyTriMF.h"
#include <iostream>

using namespace std;
using namespace Fuzzy;

int main()
{
	MemFunc* mf[2];
	TriMF* temp;

	mf[0] = new TriMF;
	mf[1] = new MemFunc;

	temp = (TriMF*)(mf[0]);

	temp->Initialize("name1", 3.2, 5.6, 9, 3,4,5);
	mf[1]->Initialize("name2", 3.2, 5.6, 9);

	mf[0] = mf[0]->Imply(.3);


	float x;
	for(int i=0; i<9; i++)
	{
		x = 3.2+(5.6-3.2)*(float)i/30.0;
		//cout << mf[0]->Evaluate(x) << ", ";
		cout << mf[0]->GetY(i) << ", ";
	}
	cout << endl;
	for(int i=0; i<mf[0]->GetPointCount(); i++)
	{
		cout << mf[0]->GetX(i) << ", ";
	}
	cout << endl;

	Variable* var = new Variable;
	var->AddMemFunc(mf, 2);

	//cout << var->IsIf("name1", 4) << endl;
	cout << var->IsIf("name2", 4) << endl;
	cout << mf[0]->Defuzzify() << endl;

	return 0;
}