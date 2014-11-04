#include <iostream>
#include <list>
#include <sstream>
using namespace std;

int charToint(char a)
{
	stringstream ss;
    ss << a;
    int x;
    ss >> x;
    return x;
}

int k = 1;
// void pp()
// {
// 	cout << "reached " << k++ << endl;
// }

int main(int argc, char const *argv[])
{
	string S;
	cin >> S;
	list<int> queue;
	list<int> *clusters = new list<int>[10];
	bool* clusterInsertedInQueue = new bool[10];
	bool* pushed = new bool[S.size()];


	for (int i = 0; i < S.size(); ++i)
	{
		pushed[i] = false;
		int x = charToint(S[i]);
		clusters[x].push_back(i);
	}
	for (int i = 0; i < 10; ++i)
	{
		clusterInsertedInQueue[i] = false;
	}

	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << i << " : ";
	// 	list<int>::iterator it;
	// 	for (it = clusters[i].begin();it!=clusters[i].end();it++)
	// 	{
	// 		cout << *it << " ";
	// 	}
	// 	cout << endl;
	// }
	int level = 0;
	queue.push_back(0);
	pushed[0] = true;
	cout << "pushed 0" << endl;

	//pp();
	int pos;
	while(!queue.empty())
    {
        int pos = queue.front();
        queue.pop_front();
        if (pos == S.size()-1)
        {
        	cout << level << endl;
        	return 0;
        }
 		if (pos != S.size()-1 && !pushed[pos+1])
 		{
 			pushed[pos+1] = true;
 			queue.push_back(pos+1);
 			pushed[pos+1] = true;
 			cout << "pushed " << pos+1 << endl;
 		}
 		//pp();
 		if (pos != 0 && !pushed[pos-1])
 		{
 			pushed[pos-1] = true;
 			queue.push_back(pos-1);
 			pushed[pos-1] = true;
 			cout << "pushed " << pos-1 << endl;
 		}
 		//pp();
        if (!clusterInsertedInQueue[S[pos]])
        {
        	//pp();
        	clusterInsertedInQueue[S[pos]] = true;
        	list<int>::iterator i;
        	for(i = (clusters[charToint(S[pos])]).begin(); i != (clusters[charToint(S[pos])]).end(); ++i)
	        {
	        	//pp();
	        	if (!pushed[*i])
	        	{
	        		queue.push_back(*i);
	        		pushed[*i] = true;
	        		cout << "pushed " << *i << endl;
	        	}
	        }
        }
        
    }

	return 0;
}