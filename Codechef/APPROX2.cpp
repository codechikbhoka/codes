#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N, K;
		cin >> N >> K;

		vector<long> numbers(N); 
		long minimal = 1000000005;
		map<long, long > MyMap;

		for (int j = 0; j < N; ++j)
		{
			cin >> numbers[j];
		}

		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < N; ++i)
		{
			MyMap[numbers[i]] = MyMap[numbers[i]] + 1	;			
		}


		
		vector<long>::iterator low,up;
		for (int i = 0; i < N-1; ++i)
		{
			
			long t = K - numbers[i];	
			low = lower_bound(numbers.begin() + i + 1, numbers.end(), t);   
			low--; 
			up  = upper_bound(numbers.begin() + i + 1, numbers.end(), t); 
			//cout << "low is " << numbers[low-numbers.begin()] << " & up is " << *up << endl;
			if (low - numbers.begin() == i)
			{
				minimal = min(minimal, numbers[i+1] - t);//cout << "minimal is " << minimal << endl;
			}
			else if (*up == 0)
			{
				minimal = min(minimal, t - numbers[N-1]);
			}
			else
			{
				minimal = min(min(abs(*low - t),abs(*up - t)), minimal);
			}
			//cout << "minimal is " << minimal << endl;
		}


		long answer = 0 ;
		for (int i = 0; i < N; ++i)
		{
			if (numbers[i] == minimal + K - numbers[i])
			{
				answer += MyMap[minimal + K - numbers[i]]  - 1;
			}
			else
			{
				answer += MyMap[minimal + K - numbers[i]];
			}
			
			if (numbers[i] == (-1)*minimal + K - numbers[i])
			{
				answer += MyMap[(-1)*minimal + K - numbers[i]]  - 1;
			}
			else
			{
				answer += MyMap[(-1)*minimal + K - numbers[i]];
			}
		}

		if (minimal == 0)
		{
			cout << minimal << " " << answer/4 << endl;
		}
		else
		{
			cout << minimal << " " << answer/2 << endl;
		}
		

	}
	
	return 0;
}



/*




*/




