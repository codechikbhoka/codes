#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		float sum=0.0;
		int m,n,k;
		cin>>n;
		float *arr=new float[n+1];
		for (int j = 1; j <= n; ++j)
		{
			cin>>arr[j];
			sum=sum+arr[j];
		}
		float *pro=new float[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>k;
			pro[i]=k/100.0;
		}
		float **array;
		array = new float*[n+1];
		int t;
		t=(int)2*sum+1;
		for (int i = 0; i <= n; ++i)
		{
			array[i]=new float[t];
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=2*sum;j++)
			{
				array[i][j]=0.0;
			}
		}
		array[1][(int)sum+(int)arr[1]]=pro[1];
		array[1][(int)sum-(int)arr[1]]=1.0-pro[1];
		for (int i = 2; i <=n; ++i)
		{
			for (int j = 0; j <=2*sum; ++j)
			{
				if(j-arr[i]<0 && j+arr[i]>2*sum)
				{
					array[i][j]=0;
				}
				else if(j-arr[i]<0 && j+arr[i]<=2*sum)
				{
					array[i][j]=array[i-1][j+(int)arr[i]]*(1-pro[i]);
				}
				else if(j-arr[i]>=0 && j+arr[i]>2*sum)
				{
					array[i][j]=array[i-1][j-(int)arr[i]]*(pro[i]);	
				}
				else
				{
					array[i][j]=(array[i-1][j-(int)arr[i]]*(pro[i]))+(array[i-1][j+(int)arr[i]]*(1-pro[i]));;	
				}
			}
		}
		/*for (int i = 1; i <=n; ++i)
		{
			for (int j = 0; j <2*sum; ++j)
			{
				cout<<array[i][j]<<"	";
			}
			cout<<endl;
		}*/
		float answer=0.0;
		for(int i=sum;i<=2*sum;i++)
		{
			answer=answer+array[n][i];
		}
		printf("%.8f\n",answer);
	}
	
	return 0;
}