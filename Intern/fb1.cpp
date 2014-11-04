#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;

	cin >> n;
	cin >> m;

	if(n==1 || m==1) 
	{
		cout<<(n+m-1) ; 
	}
	else if((n%2)&&(m%2)) 
	{
		cout<<(n*m);
	}
	else if(n%2) 
	{
		cout<<((n*m)-((n-2)*(m-2)));
	}
	else 
	{
		cout<<(n*2);
	}

	
	return 0;
}