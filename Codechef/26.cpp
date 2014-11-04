#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#define MOD 1000000009

long long fact[1000+1], invfact[1000+1];

int powmod(int base, int expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}

}

int inverse(int x){
	return powmod(x, MOD-2);

}

void init(){
	fact[0]=1;
	for(int i=1; i<=1000; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[1000]=inverse(fact[1000]);
	for(int i=1000; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;

}

long long chooser(long long n, long long r)
{
	return ((fact[n]*invfact[n-r])%MOD)*invfact[r]%MOD;
}

int main(int argc, char const *argv[])
{
	init();

	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int L;
		cin >> L;

		if (L <= 26)
		{
			cout << (chooser(26,L)*fact[L])%MOD << endl;
		}
		else
		{
			long long int temp;
			temp = (fact[26]*chooser(L-1,25))%MOD;
			cout << temp << endl;
		}
	
	}
	
	
	return 0;
}