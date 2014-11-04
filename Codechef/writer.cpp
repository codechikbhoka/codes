#include <fstream>                 //for file I/O
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
	{
		srand(time(0));
		ofstream outfile("input.txt");
		int i,j;
		char mychar;
		for (j = 0; j < 100000; ++j)
		{
			i=rand()%24;
			char mychar = 'a' + i;
			outfile << mychar;
		}

		outfile<<"\n";

		for (j = 0; j < 100000; ++j)
		{
			i=rand()%26;
			mychar = 'a'-1 + i;
			outfile << mychar;
		}

		outfile.close();


		return 0;
	}