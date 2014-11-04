#include <iostream>
#include <cmath>
using namespace std;


void func(unsigned long long int* farr, unsigned long long int* sarr)
{
	farr[1] =  4 ;
	sarr[1] =  5;
	farr[2] =  49;
	sarr[2] =  50;
	farr[3] =  498;
	sarr[3] =  501;
	farr[4] =  4987;
	sarr[4] =  5012;
	farr[5] =  49876;
	sarr[5] =  50123;
	farr[6] =  498765;
	sarr[6] =  501234;
	farr[7] =  4987653;
	sarr[7] =  5012346;
	farr[8] =  49876532;
	sarr[8] =  50123467;
	farr[9] =  498765321;
	sarr[9] =  501234678;
}

int tunc(int number, int n)
{
	int tmp1 = (int)(number / pow(10,n));   // tmp1 = 12345
	int tmp2 = ((int)(tmp1/10))*10;    // tmp2 = 12340
	int digit = tmp1 - tmp2; 

	return digit;
}

int main(int argc, char const *argv[])
{
	unsigned long long int farr[11];
	unsigned long long int sarr[11];

	func(farr, sarr);

	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		string str;
		cin >> str;

		int exist[26] = {0};
		int charID[26] = {0};
		int id = 1;
		for (int i = 0; i < str.length(); ++i)
		{
			if ((int)str[i] > 58 )
			{

				if (exist[str[i] - 'a'] == 0)
				{
					charID[str[i] - 'a'] = id;
					id++;
				}
				exist[str[i] - 'a'] = 1;
			}
		}

		int total = 0;
		for (int i = 0; i < 26; ++i)
		{
			total = total + exist[i];
		}

		//cout << "total = " << total << endl;

		for (int i = 0; i < str.length(); ++i)
		{
			if ((int)str[i] > 47 && (int)str[i] <58 )
			{
				cout << str[i];
			}
			else
			{
				if (total < 10)
				{
					cout << tunc(farr[total], total - charID[str[i] - 'a']); 
				}
				else
				{
					if (charID[str[i] - 'a'] == 1)
					{
						cout << 4 ;
					}
					else if (charID[str[i] - 'a'] <=6 && charID[str[i] - 'a'] >=2)
					{
						cout << 11 - charID[str[i] - 'a'] ;
					}
					else
					{
						cout << 10 - charID[str[i] - 'a'] ;
					}

				}
				
			}
		}

		cout << " " ;
		
		for (int i = 0; i < str.length(); ++i)
		{
			if ((int)str[i] > 47 && (int)str[i] <58 )
			{
				cout << str[i];
			}
			else
			{
				if (total < 10)
				{
					cout << tunc(sarr[total], total - charID[str[i] - 'a']); 
				}
				else
				{
					if (charID[str[i] - 'a'] == 1)
					{
						cout << 5 ;
					}
					else if (charID[str[i] - 'a'] <=6 && charID[str[i] - 'a'] >=2)
					{
						cout << charID[str[i] - 'a'] - 2 ;
					}
					else
					{
						cout << charID[str[i] - 'a'] - 1;
					}

				}
				
			}
		}

		cout << endl;


	}
	
	return 0;
}