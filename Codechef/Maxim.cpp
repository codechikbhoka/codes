#include <iostream>
using namespace std;

bool contains(int x)
{
	int l;
	while(x > 0)
	{	
		l = x%10;
		if (l==4 || l==7)
		{
			return true;
		}
		else
		{
			x = x/10;
		}
	}
}

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N, m1=0, m2=1, count=0;
		cin >> N;

		for (int i = 1; i*i <= N; i++)
		{
			if (N%i == 0)
			{
				if (contains(i))
				{
					count++;
				}

				if (i*i != N)
				{
					if (contains(N/i))
					{
						count++;
					}
				}
				

			}
			
		}


		cout << count << endl;
	}
	
	return 0;
}