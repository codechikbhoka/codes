#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		stack<int> stack;
		int N, sum = 0, j=1;
		cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			char k;
			cin >> k;
			if (k == '4')
			{
				stack.push(j);
			}
			else
			{
				if (!stack.empty())
				{
					sum = sum + stack.top();
					j=stack.top();
					stack.pop();				
				}
				
			}

		}

		cout << sum << endl;
	}
	
	

	return 0;
}