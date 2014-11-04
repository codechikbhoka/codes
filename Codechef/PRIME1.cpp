#include <iostream>
#include <fstream>
#include "math.h"
using namespace std ;
 
bool isPrime(int x);
#define MAX_NUM 32000 // 200
void gen_sieve_primes();
void Knock_Multiples_Of_FirstArg_from_SecondArgArray(int y, bool *array, int size,int start);
int squart(int x);
bool primes[MAX_NUM];
int arr[3432];
 
int main()
{
	gen_sieve_primes();
	int k = 0;
	for (int i = 2; i < 32000; ++i)
		{
			if (primes[i] == true)
			{
				arr[k] = i ;
				k++; 
			}
			
		}
 
 
	int T;
	scanf("%d",&T);
	for(int z1=0;z1<T;z1++)
	{
		int Start, End;
		scanf("%d",&Start); getchar();
		scanf("%d",&End); getchar();
 
		bool*rangeArray = new bool[End - Start + 1];
 
		for (int i = 0; i < End - Start + 1; ++i)
		{
			rangeArray[i] = true;
		}
 
		if (End<=3)
		{
			switch(Start)
			{
				case 1:
					switch(End)
					{
						case 1:
								break;
						case 2:
							printf("2\n");
							break;
						case 3:
							printf("2\n3\n");
							break;
					}
					break;
				case 2:
					switch(End)
					{
						case 2:
							printf("2\n");
							break;
 
						case 3:
							printf("2\n3\n");
							break;
					}
					break;
 
				case 3:
						printf("3\n");
						break;
 
			}
		}
 
		else
		{
			if(Start<=3)
			{
				if(Start==3)
				{
					printf("3\n");
					Start=4;
				}
				else if(Start<3)
				{
					printf("2\n3\n");
					Start=4;
				}
			}
			for (int c = 0; arr[c] <= sqrt(End); c++)
			{
				Knock_Multiples_Of_FirstArg_from_SecondArgArray(arr[c], rangeArray, End - Start + 1,Start);
			}
 
 
 
			for (int i = 0; i < End - Start + 1; ++i)
			{
				if (rangeArray[i] == true)
				 {
				 	printf("%d\n", i + Start);
				 } 
			}
 
		}
 
		
		printf("\n");
		
		
	}
	
 
	return 0;
}
 
 
void gen_sieve_primes()
{
	for(int i=0;i<32000;i++)
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
 
void Knock_Multiples_Of_FirstArg_from_SecondArgArray(int y, bool *array, int size,int start)
{
	int j,k;

	j=start/y;
	k=j*y;
	if(k<start || j==1)
	{
		k=k+y;
		if(k==y)
		{
			k=k+y;
		}
	}
	int i=k-start;
	while(i<size)
	{
		array[i]=false;
		i=i+y;
	}
 
} 