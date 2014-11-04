#include<stdio.h>
int main()

{  
	int num, sum , i , arr[500];

	printf(" type the no. ");
	scanf("%d",&num);

	arr[0]=0;arr[1]=1;

	if ( num == 1)
	{
		printf("%d",&arr[0]);
		return 0;
	}

    if ( num == 2)
    {

   printf("%d,%d",&arr[0],&arr[1]);
   return 0;
    }
     
     printf("%d,%d",&arr[0],&arr[1]);
  
    for ( i= 2; i<num; i++)

     {
          arr[i] = arr[i-1] + arr[i-2];
          printf(",%d",&arr[i]);
     }






	return 0;
}