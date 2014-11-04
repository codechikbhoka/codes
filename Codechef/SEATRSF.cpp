#include <iostream>
using namespace std;

#define MOD 1000000007

template <typename T>
T modpow(T base, T exp, int modulus)
{
    base %= modulus;
    T result = 1;
    while (exp > 0)
    {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		long long int N, M, D, X;
		cin >> N >> M >> D >> X;
		if (M < D)
		{
			cout<<"0"<<endl;
			continue;
		}
		long long int first = modpow(D+1,N,MOD);
		long long int second = (2*modpow(D,N,MOD))%MOD;
		long long int third = modpow(D-1,N,MOD);
		long long intmed ;
		if (first >= second)
		{
			intmed = first - second;	
		}
		else
		{
			intmed = MOD + first - second;
		}

		long long int ans = ((M-D)*(intmed + third)%MOD)%MOD;
		cout << ans << endl;
	}
	
	return 0;
}