#include <iostream>
#include <cmath>
using namespace std;
long long int MOD = 1000000007;
 
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		long long int a, b, da=0, db=0;
		cin >> a >> b;
		long long int temp1 = a;
		while(temp1 > 0)
		{
			da++;
			temp1 /= 10;
		}
		temp1 = b;
		while(temp1 > 0)
		{
			db++;
			temp1 /= 10;
		}
 
 		long long int sum = 0;
		if (da==db)
		{
			long long int n=b-a;
			sum=((a*(n+1))+(n*(n+1)/2))*da;
			cout << sum%MOD << endl;
			continue;
		}
 
		
 
		for (int t = da; t <= db-2; ++t)
		{
			sum = ((sum + (t+1)*(9*(long long int)pow(10,t))*(11*(long long int)pow(10,t)-1)));
		}
 
		sum = (sum + ((db*(b-(long long int)pow(10,db-1)+1)))*(2*(long long int)pow(10,db-1) -1 + (b-(long long int)pow(10,db-1)+1)));
		sum = sum + (da*((long long int)pow(10,da)-a)*(2*a + ((long long int)pow(10,da)-a) -1));
		sum = sum/2;
		cout << sum%MOD << endl;
	}
	
	return 0;
} 