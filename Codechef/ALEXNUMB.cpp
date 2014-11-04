#include "iostream"
using namespace std;

int main()
{
	int testcase;
	cin>>testcase;
	for(int i=0;i<testcase;i++)
	{
		long int variables;
		cin>>variables;
		for(int j=0;j<variables;j++)
		{
			long long int a;
			cin>>a;
		}


		cout<<(variables*(variables-1))/2<<endl;
	}

return 0;
}