#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N, K, temp, noOfEven = 0, noOfOdd = 0;
		cin >> N >> K;

		for (int i = 0; i < N; ++i)
		{
			cin >> temp;
			if (temp%2 == 0)
			{
				noOfEven++;
			}
			else
			{
				noOfOdd++;
			} 
		}

		if (K==0)
		{
			if (noOfOdd > 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			if (noOfEven >= K)
			{
				cout << "YES" << endl;
			} 
			else 
			{
				cout << "NO" << endl;
			}
			
		}

	}
	
	return 0;
}