#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#define MOD 3046201
long long traveller(int n, int k);
long long chooser(int n,int r);


struct Node
{
	int data;
	int left;
	int right;

public:
	Node()
	{}
	Node(int inputLeft, int inputRight, int inputData) : left(inputData),right(inputRight),data(inputData)
	{}
};

class SegmentTree
{
public:

	Node* list;
	int n;

	SegmentTree(int n, int*arr):n(n)
	{
		list = new Node[2*n];
		for (int i = 1; i <= 2*n - 1; ++i)
		{
			int k = (int)log2(2*n -1) - (int)log2(i);
			list[i].left = i * pow(2,k);
			list[i].right = ((i+1)*pow(2,k) -1);
		}

		for (int i = n; i <= 2*n -1; ++i)
		{
			list[i].data = arr[i-n];
		}

		for (int k = n-1; k >= 1; k--)
		{
			list[k].data = list[2*k].data + list[(2*k)+1].data;
		}
	}


	int query(int currentRoot,int u, int v)
	{
		u = u + n;
		v = v + n;

		if(u <= list[currentRoot].left && list[currentRoot].right <= v)
		{
			return list[currentRoot].data;
		}
		else if (v < list[currentRoot].left)
		{
			return 0;
		}
		else if (u > list[currentRoot].right)
		{
			return 0;
		}
		else
		{
			int l=0, r=0;
			if(u <= list[2*currentRoot].right)
			{
				l = query(2*currentRoot, u - n, v - n);
			}

			if(v >= list[2*currentRoot + 1].left )
			{
				r = query(2*currentRoot + 1, u - n, v - n);
			}

			return l+r;
		}

	}

	void update(int index, int value)
	{
		int bonus = value - list[n+index].data;

		for (int i = n+index; i > 0; i = i/2)
		{
			list[i].data = list[i].data + bonus;
		}
	}


};


long long fact[3000000+1], invfact[3000000+1];

int powmod(int base, int expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}

}

int inverse(int x){
	return powmod(x, MOD-2);

}

void init(){
	fact[0]=1;
	for(int i=1; i<=3000000; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[3000000]=inverse(fact[3000000]);
	for(int i=3000000; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;

}

long long divide(int n, int k)
{
	int divisor = n / k, num1 = 0, num2 = 0, i = 2, j, num, value1,value2,value;
	int remain = n % k;
	long long answer = fact[n];
	if (k == 1) {
		return 1;
	}
	if (remain != 0) {
		value1 = divisor + 1;
		value2 = divisor;
 		num1=remain;
 		num2=k-remain;
 		answer=(answer*powmod(invfact[value1],num1)%MOD)*powmod(invfact[value2],num2)%MOD;
		if (num1 != 0) {
			answer = (long long) answer *invfact[num1] % MOD;
		}
//cout<<answer<<endl;
		if (num2 != 0) {
			answer = (long long) answer *invfact[num2] % MOD;
		}
//cout<<answer<<endl;
		answer = answer * fact[k] % MOD;
	} else {
		value = invfact[divisor];
		for (i = 1; i <= k; i++) {
			answer = answer * value % MOD;
		}
	}
	return answer;
}



int main(int argc, char const *argv[])
{
	init();
	int N;
	cin>>N;
	int arr[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>arr[i];
	}

	SegmentTree Sg(N,arr);

	int Q;
	cin>>Q;

	string command;
	int par1, par2;


	for(int z = 0;z<Q;z++)
	{
		cin>>command;
		cin>> par1;
		cin>> par2;

		if (command.compare("change") == 0)
		{
			Sg.update(par1-1,par2);
		}
		else
		{
			int sum, people;
			long long int answer;

			sum = Sg.query(1,par1-1,par2-1);

			people = par2 - par1 + 1 ;

			cout<<divide(sum,people)<<endl;

		//                         (sum)!                                                      
		// ------------------------------------------------------------
		// {((lower+1)!)^remainder} * {((lower)!)^(people - remainder)}           

		// answer = traveller(sum,people) * chooser(people, sum%people);

		// cout<<answer%3046201<<endl;
		}

	}
	

	return 0;
}







// long long traveller(int n, int k)
// {
// 	int r = n%k;
// 	int d = n/k;

// 	int i=1,j=1;
// 	long long result=1;
// 	for (int p = 0; p < k; p++)
// 	{
// 		for (i = 1; i <= d; i++) 
// 		{
// 			result *= ( n-(j-1) );   j++;
// 			result  = result/i;
// 		}

// 	}

// 	for (int y = 0; y < r; y++)
// 	{
// 		result *= ( n-(j-1) );   j++;
// 		result  = result/(d+1);
// 	}

// 	return result;


// }

// long long chooser(int n,int r)
// {
// 	int i=0;
// 	long long result=1;
// 	if (r > n/2) {
// 		r = n - r;
// 	}
// 	for (i = 0; i < r; i++) {
// 		result *= (n-i);
// 		result /= (i+1);
// 	}
// 	return result;
// }


// SegmentTree Sg(N,arr);
// Sg.update(1,7);
// Sg.query(1,1,2);
// cout<<Sg.list[i].data ;
// cout<<Sg.list[i].left ;
// cout<<Sg.list[i].right ;
