#include <iostream>
#include "stdio.h"
using namespace std;

int main(int argc, char const *argv[])
{
	cout.precision(6);
	
	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		double T1, T2, T3, T4;
		cin >> T1;
		cin >> T2;
		cin >> T3;
		cin >> T4;

		cout << T1/(T1+T2)<<endl;

	}
	return 0;
} 