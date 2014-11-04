#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(0));
	cout << 10 << endl;
	for (int i = 0; i < 10; ++i)
	{
		int N, M;
		N = rand()%6 + 1;
		M = rand()%10 + 1;
		cout << N << " " << M << endl;
		for (int i = 0; i < M; ++i)
		{
			cout << rand()%8 + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}