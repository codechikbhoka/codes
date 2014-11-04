#include <iostream>
#include "stdio.h"
using namespace std;

#define  SIZE 100001

int main(int argc, char const *argv[])
{
	int arr[SIZE][6];
	for (int i = 0; i < SIZE; ++i)
	{
		for (int s = 0; s <= 5; ++s)
		{
			arr[i][s] = 0;
		}
		
	}

	for (int i = 2 ; i < SIZE; ++i)
	{
		if (arr[i][0] == 0)
		{
			arr[i][0] = 1;
			for (int p = 2; p <= SIZE/i; ++p)
			{
				arr[p*i][0] = arr[p*i][0] + 1 ;
			}
		}

	}

	for (int t = 2; t < SIZE; ++t)
	{
		for (int h = 1; h <=5; ++h)
			{
				arr[t][h] = arr[t-1][h] ;
			}

		if (arr[t][0] <=5)
		{
			int k = arr[t][0];
			arr[t][k] = arr[t-1][k] + 1;
			
		}
	}

	// for (int i = 0; i < SIZE; ++i)
	// 	{
	// 		cout << i << " ";
	// 	}
	// cout << endl;
	// for (int j = 0; j < 6; j++)
	// {
	// 	for (int i = 0; i < SIZE; ++i)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	

	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int A,B,K;
		cin >> A;
		cin >> B;
		cin >> K;

		int answer = arr[B][K] - arr[A-1][K];

		cout << answer << endl;
	}
	return 0;
} 