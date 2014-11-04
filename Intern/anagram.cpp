#include <iostream>
#include "cstring"
using namespace std;

int main(int argc, char const *argv[])
{
	char pat[20];
	char text[20];

	cin >> pat;	
	cin >> text; 

	int patLen = strlen(pat);
	int textLen = strlen(text);

	int pFreq[26] = {0};
	int tFreq[26] = {0};

	for (int i = 0; i < patLen; ++i)
	{
		pFreq[pat[i] - 'a']++;
		tFreq[text[i] - 'a']++;
	}


	int match = 0 ;

	for (int i = 0; i < 26; ++i)
	{
		if (pFreq[i] == tFreq[i])
		{
			match++;
		}
	}

	if (match == 26)
	{
		cout << "match at position - 0"<<endl;
	}

	int k = 0;
	int h1same =0, t1same=0, h2same =0, t2same=0;
	for (int j = patLen; j < textLen; j++, k++)
	{
		if (pFreq[text[k]-'a'] == tFreq[text[k]-'a'])
		{
			h1same = 1;
			
		}
		else
		{
			h1same = 0;
		}
		if (pFreq[text[j]-'a'] == tFreq[text[j]-'a'])
		{
			t1same = 1;
		}
		else
		{
			t1same = 0;
		}

		tFreq[text[k]-'a']-- ;
		tFreq[text[j]-'a']++ ;

		if (pFreq[text[k]-'a'] == tFreq[text[k]-'a'])
		{
			h2same = 1;
			
		}
		else
		{
			h2same = 0;
		}
		if (pFreq[text[j]-'a'] == tFreq[text[j]-'a'])
		{
			t2same = 1;
		}
		else
		{
			t2same = 0;
		}

		if (h1same == 0 && h2same == 1)
		{
			match++ ;
		}
		if (h1same == 1 && h2same == 0)
		{
			match-- ;
		}
		if (t1same == 0 && t2same == 1)
		{
			match++ ;
		}
		if (t1same == 1 && t2same == 0)
		{
			match-- ;
		}

		
		//cout << "match : " << match - 23 << endl; 	
		if (match == 26)
		{
			cout << "match at position "<< k+1 <<endl;
		}
	}

 	return 0;
}