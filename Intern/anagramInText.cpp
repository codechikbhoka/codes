#include <cstdio>
#include <cstring>
char pat[]="hello";
char text[]="ddffsdfgelolehjj";

int findanagrams(char* pat, char* text){
	int freq[26]={0};
	int pfreq[26]={0};
	int patlen = strlen(pat);
	int textlen = strlen(text);
	int matches=0;
	for (int i=0; i<patlen; i++){
		freq[text[i]-'a']++;
		pfreq[pat[i]-'a']++;
	}
	for (int i=0; i<26; i++){
		if (freq[i]==pfreq[i]) matches++;
	}
	if (matches==26) return 0;

	int i,j;
	for (i=1, j=patlen; j<textlen; i++,j++)
	{
		if (text[i-1]==text[j])
		{
			continue;
		}
		
		if (freq[text[i-1]-'a'] == pfreq[text[i-1]-'a'])
		{
			matches--;
		}

		freq[text[i-1]-'a']--;

		if (freq[text[i-1]-'a'] == pfreq[text[i-1]-'a'])
			matches++;

		if (freq[text[j]-'a'] == pfreq[text[j]-'a'])
		{
			matches--;
		}

		freq[text[j]-'a']++;

		if (freq[text[j]-'a'] == pfreq[text[j]-'a'])
		{
			matches++;
		}

		if (matches==26) return i;

	}
	return -1;
}

int main(){
	printf("%d\n", findanagrams(pat, text));
}