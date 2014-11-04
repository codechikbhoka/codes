#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void mergeSort(int* arr, int start, int end)
{
	
	if (end == start)
	{
		return;
	}
	mergeSort(arr,start, (start + end)/2);
	mergeSort(arr,(start + end)/2 + 1, end);

	int* krr = new int[end - start + 1];
	int index = 0;
	int temp1 = start;
	int temp2 = (start + end)/2 + 1;

	while(1)
	{
		if (temp1 == (start + end)/2 + 1 || temp2 == end+1)
		{
			break;
		}
		if (arr[temp1] < arr[temp2])
		{
			krr[index++] = arr[temp1++];		}
		else
		{
			krr[index++] = arr[temp2++];
		}
	}
	while(temp1 != (start + end)/2 + 1)
		{
			krr[index++] = arr[temp1++];
		}
	while(temp2 != end + 1)
		{
			krr[index++] = arr[temp2++];
		}

	for (int i = start; i <= end; ++i)
	{
		arr[i] = krr[i - start];
	}
}

int main(int argc, char const *argv[])
{
	int* arr = new int[10];
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = rand()%10;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " " ;
 	}
 	cout << endl;
	
	mergeSort(arr, 0, 9);
	
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " " ;
 	}
 	cout << endl;
	return 0;
}