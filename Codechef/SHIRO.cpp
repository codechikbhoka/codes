#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N;
		cin >> N;

		int *arr = new int[N];
		double *prob = new double[N];

		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		float k;
		for (int i = 0; i < N; ++i)
		{
			cin >> k;
			k = k/100;
			prob[i] = k;
		}

		

	}
	
	return 0;
}