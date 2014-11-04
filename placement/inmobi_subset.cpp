#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int sum;
	cin >> sum;

	int** dp = new int*[sum+1];
	for (int i = 0; i <= sum; ++i)
	{
		dp[i] = new int[N];
	}






	for (int i = 0; i < N; ++i)
	{
		dp[0][i] = 0;	
	}

	for (int i = 0; i <= sum; ++i)
	{
		dp[i][0] = (arr[0] == i)?1:0;
	}


	for (int j = 1; j <= sum; ++j)
	{
		for (int i = 1; i < N; ++i)
		{
			dp[j][i] = dp[j][i-1];
			if (j-arr[i] > 0)
			{
				dp[j][i] += dp[j-arr[i]][i-1];
			}
			else if (j-arr[i] == 0)
			{
				dp[j][i] += 1;
			}
		}
	}


	// for (int j = 0; j <= sum; ++j)
	// {
	// 	for (int i = 0; i < N; ++i)
	// 	{
	// 		cout << dp[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[sum][N-1] << endl;
	return 0;
}