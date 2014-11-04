#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		float D, U, N, M, R, C, answer=0;

		cin >> D;
		cin >> U;
		cin >> N;

		int plan = 0;
		float plan_i_costing = U*D;

		for (int i = 0; i < N; ++i)
		{
			cin >> M;
			cin >> R;
			cin >> C;
			float new_plan_i_costing = (R*U*M + C)/M;
			if (new_plan_i_costing < plan_i_costing)
			{
				plan_i_costing = new_plan_i_costing;
				plan = i + 1;
			}
		}


		cout<< plan << endl;
	}
	
	return 0;
}