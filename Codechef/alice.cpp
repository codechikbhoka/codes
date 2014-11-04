#include <iostream>
#include "stdio.h"
using namespace std;

#define MAX_NUM 1000000
int arr[78498];
int trr[78498];
bool primes[MAX_NUM];


void gen_sieve_primes()
{
	for(int i=0;i<MAX_NUM;i++)
	{
		primes[i]=true;
	}
    for (int p=2; p<MAX_NUM; p++) // for all elements in array
    {
        int c=2;
        int mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = false;
            c++;
            mul = p*c;
        }
    }
}

int squart(int x)
{
	int i;
	for ( i = 0; i*i <= x; ++i)
	{
		continue;
	}

	return i-1;
}


int main(int argc, char const *argv[])
{
	gen_sieve_primes();
	int k = 0;
	for (int i = 2; i < MAX_NUM; ++i)
		{
			if (primes[i] == true)
			{
				arr[k] = i ;
				k++; 
			}
			
		}


	int Testcases;
	scanf("%d",&Testcases);
	for(int z = 0;z<Testcases;z++)
	{
		int prod =1;

		for (int i = 0; i < 78498; ++i)
		{
			trr[i]=0;
		}

		int N;
		cin>>N;
		for (int i = 0; i < N; ++i)
		{
			int num;
			cin>>num;
			bool numisprime = true;

			for (int i = 0; arr[i] <= num; ++i)
			{
				while(num%arr[i]==0)
				{
					trr[i]++;
					num = num/arr[i];
					numisprime = false;
				}
			}
			if (numisprime)
			{
				if (num>1000)
				{
					prod = 2*prod;
				}
				else
				{
					int k=0;
					for (k= 0; arr[k]!=num; ++k)
					{}
					trr[k]++;
				}
				
			}
		}

		// for (int i = 0; i < 78498; ++i)
		// {
		// 	cout<<trr[i]<<" "<<endl;
		// }

		
		for (int i = 0; i < 78498; ++i)
		{
			prod = prod * (trr[i]+1);
		}

		cout<<prod<<endl;
	}





	return 0;
} 


