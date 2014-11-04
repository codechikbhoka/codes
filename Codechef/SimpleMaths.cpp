# include <iostream>
#include "stdio.h"
#include <stdlib.h>
using namespace std;


int length(int A1);
int max(int a, int b);
void printline(int len);
int min(int a, int b);


int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);

	int **myAs;
	myAs = (int**)malloc(T*sizeof(int*));
	for (int i1 = 0; i1 < T; i1++) 
	{
  		myAs[i1] = (int*)malloc(500 * sizeof(int));
	}

	char **myOP;
	myOP = (char**)malloc(T*sizeof(char*));
	for (int i3 = 0; i3 < T; i3++) 
	{
  		myOP[i3] = (char*)malloc(1 * sizeof(char));
	}

	int **myBs;
	myBs = (int**)malloc(T*sizeof(int*));
	for (int i2 = 0; i2 < T; i2++) 
	{
  		myBs[i2] = (int*)malloc(500 * sizeof(int));
	}

	
	getchar();

	for(int t=0;t<T;t++)
	{

		int c,i=1;
 		while (isdigit(c=getchar()))
 		{
 			myAs[t][i]=c-'0';
 			//printf("myAs[t][i] is %d\n", myAs[t][i]);
 			
 			i++;
 		}
 		
 		myAs[t][0] = i-1;
 		//printf("myAs[t][0] is %d\n", myAs[t][0]);

 		myOP[t][0] = static_cast<char>(c);
 		//printf("myOP[t][0] is %c\n", myOP[t][0]);

 		i=1;
 		while (isdigit(c=getchar()))
 		{
 			myBs[t][i]=c-'0';
 			//printf("myBs[t][i] is %d\n", myBs[t][i]);
 			
 			i++;
 		}
 		myBs[t][0] = i-1;
 		//printf("myBs[t][0] is %d\n", myBs[t][0]);
	}



	
	for (int t = 0; t < T; ++t)
	{
		/*int A,B;
		
		A = myAs[d];
		B = myBs[d];*/
		char OP;
		int lenA, lenB,FirstIntermediate;
		lenA=myAs[t][0];
		lenB=myBs[t][0];
		OP = myOP[t][0];

		if(OP == '+')
		{
			int k1,width;
			int lenk1 = myAs[t][0];
			int lenk2 = myBs[t][0];
			int k3 = max(lenk1,lenk2);

			int *myCs;
			myCs = (int*)malloc((k3+1)*sizeof(int));
			myCs[0] = 0;

			int carry=0;
			int gaplength = max(lenk1,lenk2) - min(lenk1,lenk2);

			
			if (lenk1 >= lenk2)
			{
				for(int j = k3; j>gaplength; j--)
				{
					myCs[j] = (myAs[t][j] + myBs[t][j-gaplength] + carry)%10;
					carry = (myAs[t][j] + myBs[t][j-gaplength] + carry)/10;
				}
				for(int j = gaplength; j>0; j--)
				{
					myCs[j] = (myAs[t][j] + carry)%10;
					carry = (myAs[t][j] + carry)/10;
				}
				
			}
			else
			{
				for(int j = k3; j>gaplength; j--)
				{
					myCs[j] = (myAs[t][j-gaplength] + myBs[t][j] + carry)%10;
					carry = (myAs[t][j-gaplength] + myBs[t][j] + carry)/10;
				}
				for(int j = gaplength; j>0; j--)
				{
					myCs[j] = (myBs[t][j] + carry)%10;
					carry = (myBs[t][j] + carry)/10;
				}
			}
				

			myCs[0] = carry;
			int lenAplusB = k3 + carry;

			width = max(myBs[t][0]+1,lenAplusB);

			for(k1=1;k1<=width-myAs[t][0];k1++)
			{
				printf(" ");
			}
			for(int r=1;r<=myAs[t][0];r++)
			{
				printf("%d",myAs[t][r]);
			}
			printf("\n");

			for(k1=1;k1<width-myBs[t][0];k1++)
			{
				printf(" ");
			}
			printf("%c",OP);
			for(int r=1;r<=myBs[t][0];r++)
			{
				printf("%d",myBs[t][r]);
			}
			printf("\n");

			FirstIntermediate = lenAplusB;
			printline(max(FirstIntermediate,myBs[t][0]+1));

			for(int k1=1;k1<=(max(FirstIntermediate,myBs[t][0]+1))-FirstIntermediate;k1++)
			{
				printf(" ");
			}
			if (carry==1)
			{
				printf("1");
			}
			for(int r=1;r<=k3;r++)
			{
				printf("%d",myCs[r]);
			}
			printf("\n");
		}

		
		else if(OP == '-')
		{
			int k1,width;
			int lenk1 = myAs[t][0];
			int lenk2 = myBs[t][0];
			int k3 = lenk1;

			int *myCs;
			myCs = (int*)malloc((k3+1)*sizeof(int));
			myCs[0] = 0;

			int gaplength = lenk1 - lenk2;

			width = max(myAs[t][0],myBs[t][0]+1);

			for(k1=1;k1<=width-myAs[t][0];k1++)
			{
				printf(" ");
			}

			for(int r=1;r<=myAs[t][0];r++)
			{
				printf("%d",myAs[t][r]);
			}
			printf("\n");

			for(k1=1;k1<width-lenB;k1++)
			{
				printf(" ");
			}
			printf("%c",OP);
			for(int r=1;r<=myBs[t][0];r++)
			{
				printf("%d",myBs[t][r]);
			}
			printf("\n");


			/*********error in this code     see example 16785 - 1*/
			int flag = gaplength;
			for(int m=gaplength;m>0;m--)
			{
				if(myAs[t][m]==0)
					flag--;
				else
				{
					break;
				}
			}

			myAs[t][flag] = myAs[t][flag] - 1;  /*********error in this code*/

			for(int m=flag+1;m<=gaplength;m--)
			{
				myAs[t][m] = 9;
			}

			for(int m=gaplength+1;m<=k3;m++)
			{
				if(myAs[t][m] < myBs[t][m-gaplength])
				{
					if (m-1 !=flag)
					{
						myAs[t][m-1] = myAs[t][m-1] - 1;
					}
					
					myAs[t][m] = myAs[t][m] + 10;
				}
			}

			for(int j = k3; j>gaplength; j--)
			{
				myCs[j] = (myAs[t][j] - myBs[t][j-gaplength]);
			}
			for(int j = gaplength; j>0; j--)
			{
				myCs[j] = myAs[t][j];
			}
			int tlag;
			for (tlag = 0; tlag <= k3; tlag++)   //tlag will mark first non-zero digit in answer
			{
				if (myCs[tlag] != 0)
				{
					break;
				}
			}
			int lenAminusB = k3 - tlag + 1;

			FirstIntermediate = lenAminusB;          
			printline(max(FirstIntermediate,myBs[t][0]+1));

			for(k1=1;k1<=(max(FirstIntermediate,lenB+1))-FirstIntermediate;k1++)
			{
				printf(" ");
			}

			for(int r=tlag;r<=k3;r++)
			{
				printf("%d",myCs[r]);
			}
			printf("\n");

		}

		/*
		else if(OP == '*')
		{
			int k1,width;
			width = max(length(A*B),length(B)+1);

			for(k1=1;k1<=width-lenA;k1++)
			{
				printf(" ");
			}
			printf("%d\n",A);

			for(k1=1;k1<width-lenB;k1++)
			{
				printf(" ");
			}
			printf("%c%d\n",OP,B);

			FirstIntermediate = length(A*(B%10));
			
			for(k1=1;k1<=width-max(FirstIntermediate,lenB+1);k1++)
			{
				printf(" ");
			}

			printline(max(FirstIntermediate,myBs[t][0]+1));

			int k1,temp,count=0;
			int B1=B;
			int width = max(length(A*B),length(B)+1);

			while(B1!=0)
			{
				temp = length(A*(B1%10));
				for(k1=1;k1<=width-temp - count;k1++)
				{
					printf(" ");
				}
				printf("%d\n",A*(B1%10));
				B1=B1/10;
				count++;
			}
			if (length(B) > 1)
			{
				printline(length(A*B));
				printf("%d\n",A*B);
			}

		}*/


		printf("\n");

	}

	return 0;
}






int max(int a, int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int min(int a, int b)
{
	if(a>=b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

void printline(int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("-");
	}
	printf("\n");
}

int length(int A1)
{
	int lenA1=0;

	if (A1==0)
	{
		lenA1=1;
	}
	else
	{
		while(A1!=0)
		{
			A1 = A1/10;
			lenA1++;
		}
	}
	
	return lenA1;
}

