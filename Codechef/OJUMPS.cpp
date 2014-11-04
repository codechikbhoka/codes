#include <iostream>
using namespace std;

bool is6n(long long a)
{
	long long x = 0;
	for (long long int i = a; i>0; i=i/10)
	{
		x = x + i%10;
	}
	if (a%2==0 && x%3 == 0)
	{
		return true;
	}

	return false;
}

int main(int argc, char const *argv[])
{
	long long a;
	cin >> a;
	if(is6n(a) || is6n(a+5) || is6n(a+3))
	{
	 	cout << "yes" << endl;
	} 
	else
	{
		cout << "no" << endl;
	}
	return 0;
}