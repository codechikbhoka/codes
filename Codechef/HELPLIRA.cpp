#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, x1, y1, x2, y2, x3, y3, min = 1000000, max = 0, mindex, maxdex;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		int A = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
		if (A < 0)
		{
			A = (-1)*A;
		}
		if (A <= min)
		{
			min = A;
			mindex = i;
		}
		if (A >= max)
		{
			max = A;
			maxdex = i;
		}

	}

	cout << mindex + 1 << " " << maxdex + 1 << endl;
	return 0;
}