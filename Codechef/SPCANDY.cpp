#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		long long int N,K;
		cin >> N;
		cin >> K;
		if (K > 0)
		{
			cout<< N/K << " " << N%K<<endl;
		}
		else
		{
			cout<< 0 << " " << N<<endl;
		}

	}
	
	return 0;
}