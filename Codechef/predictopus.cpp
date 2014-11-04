#include <iostream>
#include "stdio.h"
using namespace std;
#define n 10000.0

double maximum(double a, double b)
{
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; ++i)
	{
		double p;
		cin>>p;
		printf("%.6lf\n", maximum(n*(3.0*p - 2.0*p*p),n*(p+1.0-2.0*p*p)));
	}
	return 0;
}