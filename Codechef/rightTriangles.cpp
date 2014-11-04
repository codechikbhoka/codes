#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int count = 0;
	int x1,x2,x3,y1,y2,y3;

	for (int i = 0; i < N; ++i)
	{
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		cin >> x3;
		cin >> y3;
		bool rtTri = false;
		if ( (pow(x2 - x1, 2) + pow(y2-y1,2) + pow(x3 - x1,2) + pow(y3-y1,2) == pow(x2-x3,2) + pow(y2-y3,2)  ) )
		{
			rtTri = true;
		}
		else if (pow(x2-x3,2) + pow(y2-y3,2) + pow(x3 - x1,2) + pow(y3-y1,2) == pow(x2 - x1, 2) + pow(y2-y1,2))
		{
			rtTri = true;
		}
		else if (pow(x2-x3,2) + pow(y2-y3,2) + pow(x2 - x1, 2) + pow(y2-y1,2) == pow(x3 - x1,2) + pow(y3-y1,2))
		{
			rtTri = true;
		}

		if (rtTri)
		{
			count++;
		}
	}

	cout << count <<endl;
	return 0;
}