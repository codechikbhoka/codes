#include <iostream>
#include "stdio.h"
#include "stdint.h"
using namespace std;
 
long long int chooser(int N, int K);
 
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int z1=0;z1<T;z1++)
	{
		int N,K;
		scanf("%d",&N); getchar();
		scanf("%d",&K); getchar();
 
		printf("%lld\n",chooser(N-1,K-1));
	}
 
	return 0;
}
 
// long long int chooser(int N, int K)
// {
// 	long long int numerator = 1, denominator = 1 ,max;
// 	if (K > N-K)
// 	{
// 		max = K;
// 	}
// 	else
// 	{
// 		max = N-K;
// 	}

// 	for (int i = N; i > max; i--)
// 	{
// 		numerator = numerator * i;		
// 	}
 
// 	for (int i = N-max; i > 1; i--)
// 	{
// 		denominator = denominator * i;		
// 	}
 
// 	return numerator/denominator ;
// } 

long long chooser(int n,int r){
  int i=0;
  long long result=1;
  if (r > n/2) {
    r = n - r;
  }
  for (i = 0; i < r; i++) {
    result *= (n-i);
    result /= (i+1);
  }
  return result;
}