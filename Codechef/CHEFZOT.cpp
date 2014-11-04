#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, max=0, count=0;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (arr[i]==0)
		{
			if (count > max)
			{
				max = count;
			}
			count=0;
		}
		else
		{
			count++;
			if (count > max)
			{
				max = count;
			}
		}
	}

	cout << max << endl;


	return 0;
}