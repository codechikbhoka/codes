#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int h = 0; h < testcases; ++h)
	{
		int N;
		cin >> N;
 		long* arr = new long[N];
 		int* freq = new int[N];
 		for (int i = 0; i < N; ++i)
 		{
 			freq[i] = 0;
 		}
 		bool flag = true;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < N; ++i)
		{
			if (arr[i]%N == 0)
			{
				cout << "1\n" << i + 1 << endl; 
				flag = false;
				break;
			}
		}

		
		if (flag)
		{
			arr[0] = arr[0]%N;
			for (int j = 1; j < N; ++j)
			{
				arr[j] = (arr[j-1] + arr[j])%N;	
				freq[arr[j]]++; 
				if (arr[j] == 0)
				{
					cout << j+1 << endl; 
					for (int i = 0; i <=j; ++i)
					{
						cout << i + 1 << " ";
					}
					cout << endl;
					flag = false;
					break;
				}
			}
		}

		if (flag)
		{	
			int repeatingRemainder;
			
			for (int i = 0; i < N; ++i)
			{
				if (freq[i] > 1)
				{
					repeatingRemainder = i;
					break;
				}

			}

			//cout << "repeatingRemainder is " << repeatingRemainder << endl;
			int first = -1, second;
			for (int i = 0; i < N; ++i)
			{
				if (arr[i] == repeatingRemainder && first == -1)
				{
					first = i;
				}
				else if (arr[i] == repeatingRemainder && first != -1)
				{
					second = i;
					break;
				}

			}

			cout << second - first << endl;
			for (int i = first+1; i <= second; ++i)
			{
				cout << i + 1 << " " ; 
			}
			cout << endl;
		}

	}
	
	return 0; 
}