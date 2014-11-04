#include <iostream>
#include "stdio.h"
#include <map>
using namespace std;

std::map<long long int, long long int> mymap;
std::map<long long int, long long int>::iterator it;


bool mymapContains(long long int n)
{
	it=mymap.find(n);
	if (it == mymap.end())
	{
		return false;
	}
	else
	{
		return true;
	}

}

long long int F(long long int n)
{
	if (n<12)
	{
		return n;
	}
	else if (mymapContains(n))
	{
		return mymap.find(n)->second ;
	}
	else
	{
		long long int c = F(n/2) + F(n/3) + F(n/4) ;
		mymap[n] = c;
		return c;
	}
	
}
 
 
int main()
{
	long long int n;
 
	for (int j = 0; j < 10; ++j)
	{
		cin >> n;
		cout << F(n) << endl;
	}
 
 
	return 0;
}
