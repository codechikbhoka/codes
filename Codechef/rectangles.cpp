#include <iostream>
#include "stdio.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int N, M , K ;

		cin >> N;
		cin >> M;
		cin >> K;

		if (N == 1 && M == 1)
		{
			cout<<"0"<<endl;
			continue;
		}
		else if (N==1 && M==2)
		{
			cout<<"0"<<endl;
			continue;
		}
		else if (N==2 && M==1)
		{
			cout<<"0"<<endl;
			continue;
		}
		else if(N == 1 || M == 1)
		{
			cout<<K<<endl;
			continue;
		}
		else
		{
			cout<<(K+1)/2<<endl;
		}

	}
	return 0;
} 