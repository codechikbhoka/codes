#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

void applyOperator(ll &ans, ll y, char op)
{
	if (op == '+')
	{
		ans += y;
	}
	if (op == '-')
	{
		ans -= y;
	}
	if (op == '*')
	{
		ans *= y; 
	}
}

ll paren(string x)
{
	ll ans = 0;
	static int i=1;
	char op = '+';
	while(1)
	{
		if (x[i] == ')')
		{
			i++;
			return ans;
		}
		else if (x[i] == '(')
		{
			i++;
			applyOperator(ans, paren(x) , op);
		}
		else if ('0' <= x[i] && x[i] <= '9')
		{
			applyOperator(ans, x[i] - '0' , op);
			i++;
		}
		else
		{
			op = x[i];
			i++;
		}

	}

}

int main(int argc, char const *argv[])
{
	string x;
	cin >> x;
	x = '(' + x + ')';
	cout << paren(x) << endl;


	return 0;
}