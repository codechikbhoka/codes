#include <iostream>
#include <list>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int N, M, timesCleaned = 0;
		map<int, int> CustomerSeated;
		list<int> CustomerOrderNumber[405];
		list<int> distinctCustomers;
		int numberTablesCovered = 0;


		cin >> N >> M;

		int* arr = new int[M];


		for (int i = 0; i < M; ++i)
		{
 	 		cin >> arr[i];
 	 		CustomerOrderNumber[arr[i]].push_back(i);


 	 		bool insertNewCustomer = true;
 	 		for (list<int>::iterator j = distinctCustomers.begin(); j != distinctCustomers.end(); ++j)
 	 		{
 	 			if (arr[i] == *j)
 	 			{
 	 				insertNewCustomer = false;
 	 			}
 	 		}
 	 		if (insertNewCustomer)
 	 		{
 	 			distinctCustomers.push_back(arr[i]);
 	 		}
		}

		// cout << "Distinct Customers" << endl;
		// for (list<int>::iterator j = distinctCustomers.begin(); j != distinctCustomers.end(); ++j)
 	// 	{
		// 	cout << *j << " ";
 	// 	}
 	// 	cout << endl;

		for (int i = 0; i < M; ++i)
		{
			CustomerOrderNumber[arr[i]].pop_front();
			if (CustomerSeated[arr[i]] == 0)
			{
				int maxOrderNumber = -1;

				int CustomerToRemove ;

				if (numberTablesCovered < N)
				{
					numberTablesCovered++;
					CustomerSeated[arr[i]] = 1;
					//cout << "Seated customer " << arr[i] << endl;
					timesCleaned++;
					continue;
				}
				

				for (list<int>::iterator t = distinctCustomers.begin(); t != distinctCustomers.end(); ++t)
				{
					if (CustomerSeated[*t] && CustomerOrderNumber[*t].empty())
					{
						CustomerToRemove = *t;
						break;
					} else if (CustomerSeated[*t] && CustomerOrderNumber[*t].front() > maxOrderNumber)
					{
						maxOrderNumber = CustomerOrderNumber[*t].front();
						CustomerToRemove = *t;
					}
				}
				CustomerSeated[CustomerToRemove] = 0;
				// cout << "Removed customer " << CustomerToRemove << endl;
				CustomerSeated[arr[i]] = 1;
				// cout << "Seated customer " << arr[i] << endl;
				timesCleaned++;
			}
		}

		cout << timesCleaned << endl;
	}
	
	return 0;
}