#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		long long N,M;
		long long v;
		cin >> N >> M ;

		if (N%2 == 0 || M%2 == 0)
		{
			cout << "1/2" << endl;
		}
		else
		{
			v = M*N;
			cout << (v-1)/2 << "/" << v << endl;
		}


	}
	
	return 0;
}