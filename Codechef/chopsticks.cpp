#include <iostream>
using namespace std;

void merge(int*,int*,int,int,int);
void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

int main(int argc, char const *argv[])
{
	int N, D;
	cin >> N;
	cin >> D;
	int *arr = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

    int num;
    num = N;
    int b[num]; 
    mergesort(arr,b,0,num-1);


	int k=-1, sum=0, i;

	for (i = 1; i < N; ++i)
	{
		if (arr[i] - arr[i-1] > D)
		{
			sum = sum + (((i-1)-k)/2);
			k = i-1;
		}
	}

	sum = sum + (((i-1)-k)/2);

	cout << sum <<endl;

	return 0;
}