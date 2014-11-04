#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		long long X, Y, first, second;
		cin >> X >> Y;
		bool oilSpilledHere = false;
    	

		if (Y%2 == 0)
		{
			if (Y>0)
			{
				first = (-1) * Y;
				second = Y - 1; 
			}
			else if (Y < 0)
			{
				first = Y;
				second = (-1) * (Y-1); 
			}
			else
			{
				first = 0;
				second = 1; 
			}

			if(first <= X && X <= second)
			{
				oilSpilledHere = true;
			}
		}

		if ( (X>0 && X%2 == 1)  || (X<0 && X%2==0) )
		{
			if (X>0)
			{
				first = (-1)*(X-1);
				second = X + 1; 
			}
			else if (X < 0)
			{
				first = X;
				second = (-1) * X; 
			} 
			else
			{
				first = 0;
				second = 0; 
			}

			if(first <= Y && Y <= second)
			{
				oilSpilledHere = true;
			}
		}

		if (oilSpilledHere)
		{
			cout << "YES" << endl;
		}
		else 
		{
			cout << "NO" << endl;
		}

		
	}
	
	return 0;
}