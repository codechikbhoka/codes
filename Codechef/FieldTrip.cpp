#include <iostream>
using namespace std;
#include "stdio.h"
#include <iomanip>

double C(double N, double K);
double Complex(double i, double S, double M, double N, double K);

int main(int argc, char const *argv[])
{
	double T;
	scanf("%lf",&T);
	getchar();
	for(int z1=0;z1<T;z1++)
	{
		std::cout.setf(std::ios::fixed);
	    std::cout.precision(6);

	    double S,N,M,K;
	    scanf("%lf",&S);
	    getchar();
	    scanf("%lf",&N);
	    getchar();
	    scanf("%lf",&M);
	    getchar();
	    scanf("%lf",&K);
	    getchar();

	    double sum1 = 0;
	    for (double i = 0; i < M-K; i++)
	    {
	    	sum1 = sum1 + Complex(i,S,M,N,K);
	    }

	    double sum2 = C(S-1,N-1);

	    cout<<sum1/sum2<<endl;

	}
	
 return 0;
}


double C(double N, double K)
{
	double J1 = N, J2=K;

	if (N<K)
	{
		return -1;
	}
	else if(K==0)
	{
		return 1;
	}
	for (double i = N-1;i>N-K;i--)
	{
		J1 = J1*i;
	}

	for (double i = K-1;i>1;i--)
	{
		J2 = J2*i;
	}

	return J1/J2;
}

double Complex(double i, double S, double M, double N, double K)
{
	if (M-1<K+i || S-M < N-K-(i+1))
	{				
		return 0;
	}

	else if (N-K-(i+1) < 0)
	{
		return 0;  
	}
	else
	{
		return C(M-1,K+i) * C(S-M,N-K-(i+1));	
	}
	
}


