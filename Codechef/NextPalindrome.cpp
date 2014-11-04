#include <iostream>
#include "stdio.h"
using namespace std;
bool isODD(int X);

int main(int argc, char const *argv[])
{
	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int x; cin>>x;

		int t1 = x,length;
		for ( length = 0; t1 > 0; length++)
		{
			t1 = t1/10;
		}

		int middle = (length+1)/2;
		int straight = x, t3 = x;
		int rev=0;
		if (isODD(length))
		{
			for (int i = 1; i <= middle; ++i)
			{
				rev = rev*10 + straight%10;
				straight = straight/10;
			}

			straight = straight*10 + rev%10;
		}
		else
		{
			for (int i = 1; i <= middle; ++i)
			{
				rev = rev*10 + straight%10;
				straight = straight/10;
			}

		}
		
		int max,min;
		if (straight > rev)
		{
			max = straight;
			min = rev;
		}
		else
		{
			max = rev;
			min = straight;
		}

	}
	return 0;
}

bool isODD(int X)
{
	if (x%2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}