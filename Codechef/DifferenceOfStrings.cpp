#include <iostream>
#include <cstring>
#include <time.h>
#include <fstream>    
using namespace std;

clock_t t1 = clock();

int main(int argc, char const *argv[])
{
	string A,B,C,K;
	int t=-1,r;

	ifstream infile("input.txt");
	infile >> A;
	infile >> B;
	
	//cin >> A;
	//cin >> B;
	int count = 0;

	for (int i = 0; i < B.length(); ++i)
	{
		for (int j = 1; j <= B.length()-i; ++j)
		{
			K = B.substr(i,j);
			r = B.find(K);
			t = A.find(K);
			if (t==-1 && r==i)
			{
				count = count + (B.length() - (i+j-1));
				break;
			}
			t=-1;
		}
		
	}

	for (int i = 0; i < A.length(); ++i)
	{
		for (int j = 1; j <= A.length()-i; ++j)
		{
			K = A.substr(i,j);
			r = A.find(K);
			t = B.find(K);
			if (t==-1 && r == i)
			{
				count = count + (A.length() - (i+j-1));
				break;
			}
			t=-1;
		}
		
	}

	cout<<count<<endl;
	clock_t t2 = clock();
	cout << t2<<endl;
    cout<<"The running time is " << ((double)(t2-t1))/CLOCKS_PER_SEC<<" sec"<<endl;

	return 0;
}