#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	double varCount;
	double standardDeviation = 0;
	int factIn = 0;
	int factOut = 1;
	double mean = 0.0;
	cout << "How many positive numbers(must be less than 10 do you want to calculate: ";
	cin >> varCount;
	int vars[5] = {};
	for (int v = 0; v < varCount; v++) {
		cin >> vars[v];
		mean += vars[v];
		if (vars[v] >= 0) {
			factIn++;
		}
	}
	mean /= varCount;

	int subVars[5] = {};
	double mean2 = 0;
	for (int v = 0; v < varCount; v++) {
		subVars[v] = pow((vars[v] - mean),2.0);
		mean2 += subVars[v];
	}

	mean2 /= varCount;

	standardDeviation = sqrt(mean2);
	
	
	cout << endl << endl << "Standard Deviation = " << standardDeviation << endl;


	for (int f = factIn; f > 0; f--) {
		factOut *= f;
	}
	cout << "Factorial of " << factIn << " = " << factOut << endl;
}
