#include <iostream>
using namespace std;

int left(int index)
{
	return 2*index + 1; 
}

int right(int index)
{
	return 2*(index + 1);
}

int parent(int index)
{
	return (index-1)/2;
}

void swap(int& a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b; 
}


void heapify(int *arr, int index, int size)
{
	int min = index;

	if (left(index) <= size && arr[left(index)] < arr[min])
	{
		min = left(index);
	}

	if (right(index) <= size && arr[right(index)] < arr[min])
	{
		min = right(index);
	}

	if (min != index)
	{
		swap(arr[index] , arr[min]);
		heapify(arr, min, size);
	}

}

void BuildHeap(int *arr, int n)
{
	for (int i = (n-1)/2; i >= 0; i--)
	{
		heapify(arr,i,n);
	}
}


void increasekey(int *arr, int index, int value)
{
	arr[index] = value;
	while(arr[index] < arr[parent(index)] && index > 0)
	{
		swap(arr[index], arr[parent(index)]);
		index = parent(index);
	}
	
}

void insert(int *arr, int k, int&n)
{
	n = n+1;
	increasekey(arr, n , k);

}

int extractMin(int *arr, int& n)
{
	swap(arr[0] , arr[n]);
	n = n-1;
	heapify(arr, 0 , n);
	return arr[n+1];
}




int main(int argc, char const *argv[])
{

	int arr[] = {2,5,3,8,6,23,43,56,54,27,63};
	int size = sizeof(arr)/sizeof(int); 
	BuildHeap(arr, size); 
	insert(arr, 7 , size); 
	for (int i = 0; size > 0; ++i)
	{
		cout << extractMin(arr, size) << endl;
	} 
	
	
	
	return 0;
}