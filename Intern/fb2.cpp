#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	int total = 0, less;
	int k = str.length();

	for (int i = 0; i < str.length(); ++i)
	{
		less = str[i] - 'a';
		if (i>0 && (int)str[i-1] < (int(str[i])))
		{
			total += (less-1) * pow(25, k - 1);
		}
		else if (i>0 && (int)str[i-1] == (int(str[i])))
		{
			total += (less) * pow(25, k - 1);
			break;
		}
		else
		{
			total += less * pow(25, k - 1);
		}
		
		k--;
	}

	bool selfSstring = true;
	for (int i = 1; i < str.length(); ++i)
	{
		if (str[i] == str[i-1])
		{
			selfSstring = false;
		}
	}

	if (selfSstring)
	{
		total++;
	}

	cout << total << endl;
	return 0;
}