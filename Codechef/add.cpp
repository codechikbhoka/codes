#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double P[100003];
	P[1] = 0.45;
	for (int i = 2; i < 100001; ++i)
	{
		P[i] = ((1-P[i-1])*(0.45)) + (P[i-1]*(0.55));
	}

	double F[100003];
	F[1] = 0.45;
	for (int i = 2; i < 100001; ++i)
	{
		F[i] = F[i-1] + P[i];
	}
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N;
		cin >> N;

		printf("%.10lf\n",F[N]);
	}
	return 0;
}