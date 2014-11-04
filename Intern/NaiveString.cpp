#include <iostream>
#include "string.h"
using namespace std;

int main(int argc, char const *argv[])
{
	char k;
	int num = 0;
	k = cin.get();
	while( k != '\n')
	{
		do
		{
			if (k != ' ')
			{
				num = 10*num + k-'0'; 		
			}
			k = cin.get();
			
		}while(k!=' ' && k!= '\n');
		cout << num << endl;
		num = 0;
	}

	return 0;

}