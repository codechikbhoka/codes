#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int X;
	double  Y;
	cin >> X;
	cin >> Y;

	if (X%5 == 0 && Y>= X+0.5)
	{
		cout << Y - X - 0.5 << endl;
	}
	else
	{
		cout << Y << endl;
	}
	

	return 0;
}