#include <iostream>
using namespace std;

void IntelligentlyPush(int d, int *bottlelist, int size)
{
	int temp = 100001, index;
	for (int i = 0; i < size; ++i)
	{
		if(bottlelist[i] < temp)
		{
			temp = bottlelist[i];
			index = i;
		}
	}

	if (d > bottlelist[index])
	{
		bottlelist[index] = d;
	}

}


int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int n,m,C, answer=0;
		cin >> n;
		cin >> m;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		 {
		 	arr[i] = 0;
		 }

		int k;
		for (int i = 0; i < m; ++i)
		{
			cin >> k;
			arr[k]++;
		}

		for (int i = 0; i < n; ++i)
		{
			int size = arr[i];
			cin >> C;
			int *bottlelist = new int[size];

			// arr[i] denotes how many times a room i has been visited
			for (int j = 0; j < size; ++j)
			{
				bottlelist[j] = 0;
			}
			int d;
			for (int i = 0; i < C; ++i)
			{
				cin >> d;
				IntelligentlyPush(d, bottlelist, size);
			}

			int newsum = 0;
			for (int p = 0; p < size; ++p)
			{
				newsum = newsum + bottlelist[p];
			}

			answer = answer + newsum;
		}

		cout<<answer<<endl;
	}
	
	return 0;
}