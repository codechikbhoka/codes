#include <bits/stdc++.h>
using namespace std;

void sWap(vector<int>& v, int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

int partition(vector<int>& v, int start, int end)
{
	int pivot = v[end];
	int i=start-1;

	for (int j = start; j <= end-1; ++j)
	{
		if (v[j] <= pivot)
		{
			i++;
			sWap(v,i,j);
		}
	}

	sWap(v,i+1,end);
	return i+1;
}

void quicksoRt(vector<int> &v, int start, int end)
{
	if (start < end)
	{		
		int pivot = partition(v, start, end);
		quicksoRt(v, start, pivot-1);
		quicksoRt(v, pivot+1, end);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> v;
	srand(time(0));

	int N=25;

	for (int i = 0; i < N; ++i)
	{
		v.push_back(rand()%100);
		cout << v[i] << " ";
	}
	cout<< endl;

	quicksoRt(v,0,v.size()-1);

	for (int i = 0; i < N; ++i)
	{
		cout << v[i] << " ";
	}
	cout<< endl;

	return 0;

}