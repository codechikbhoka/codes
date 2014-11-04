#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		map<char,char> mymap;
		int N;
		cin >> N;
		mymap['0'] = '0';
		mymap['1'] = '1';
		mymap['2'] = '2';
		mymap['3'] = '3';
		mymap['4'] = '4';
		mymap['5'] = '5';
		mymap['6'] = '6';
		mymap['7'] = '7';
		mymap['8'] = '8';
		mymap['9'] = '9';
		mymap['.'] = '.';;
		

		char c,p;
		for (int i = 0; i < N; ++i)
		{
			cin >> c >> p;
			mymap[c] = p;
		}

		string ans;
		cin >> ans;
		//cout << "input is " << ans << endl;
		int j=0;
		while(mymap[ans[j]] == '0')
		{
			j++;
		}
		int start = j;
		bool containsDecimal = false;
		while(j<ans.size())
		{
			if (mymap[ans[j]] == '.')
			{
				containsDecimal = true;
				
			}

			ans[j] = mymap[ans[j]];
			//cout <<"ans["<<j<<"] is " << ans[j] <<endl;;
			j++;
		}
		//cout << "\nchanged ans is " << ans << endl;
		int backzeroes = 0;
		if (containsDecimal)
		{
			for (int k = ans.size(); k > 0 ; k--, backzeroes++)
			{
				if (ans[k-1] != '0')
				{
					break;
				}
			}
		}
		//cout << "\nnum of backzeroes is " << backzeroes << endl ;
		int t = ans.size() - backzeroes;
		if (ans[t-1] == '.')
		{
			t--;
		}

		if (t==start)
		{
			cout << "0";
		}
		else
		{
			for (int i = start; i < t; ++i)
			{
				cout<<ans[i];
			}	
		}
		
		cout<<endl;

	}
	
	return 0;
}