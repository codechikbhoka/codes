#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N, sum =0;
		cin >> N;
		int arr[N], krr[N];
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < N; ++i)
		{
			cin >> krr[i];
		}

		bool allzero = true;
		for (int i = 0; i < N; ++i)
		{
			if (krr[i] - arr[i] != 0)
			{
				allzero = false;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			sum = sum + krr[i] - arr[i];
		}

		if (allzero)
		{
			cout << "0" << endl;
		}
		else
		{
			switch(N)
			{
				case 1:
					if (arr[0] >= krr[0])
					{
						cout << arr[0] - krr[0] << endl;
					}
					else
					{
						cout << "-1" << endl;
					}
					break;

				case 2:
					if (sum == 0)
					{
					 	cout << "1" << endl;
					}
					else
					{
						cout << "-1" << endl;
					}
					break;

				default:
					if (sum == 0)
					{
					 	cout << "-1" << endl;
					}
					else if (sum/(N-2) > 0 && sum%(N-2) == 0)
					{
						int M = sum/(N-2);
						bool okay = true;
						for (int i = 0; i < N; ++i)
						{
							if ((M-krr[i]+arr[i]) <0 || (M-krr[i]+arr[i])%2 != 0)
							{
								okay = false;
							}
						}
						if (okay)
						{
							cout << M << endl;
						}
						else
						{
							cout << "-1" << endl;
						}
						
					}
					else
					{
						cout << "-1" << endl;
					}
					break;


			}
		}
		
		
	}
	
	return 0;
}