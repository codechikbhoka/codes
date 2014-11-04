#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Graph{
	int V;
	list<int>* adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	bool bidirectionalBFS(int from, int to)
	{

		if (from == to)
		{
			return true;
		}

		unordered_set<int> setFrom;
		unordered_set<int> setTo;

		list<int> queueFrom,queueTo;

		setFrom.insert(from);
		setTo.insert(to);
		queueFrom.push_back(from);
		queueTo.push_back(to);
		

		while(!queueFrom.empty() && !queueTo.empty())
		{
			int top = queueFrom.front();
			queueFrom.pop_front();
			list<int>::iterator it;
			for (it=adj[top].begin(); it!=adj[top].end(); it++)
			{
				if (setTo.find(*it) != setTo.end())
				{
					return true;
				}
				if (setFrom.find(*it) == setFrom.end())
				{
					setFrom.insert(*it);
					queueFrom.push_back(*it);
				}
			}

			top = queueTo.front();
			queueTo.pop_front();
			for (it=adj[top].begin(); it!=adj[top].end(); it++)
			{
				if (setFrom.find(*it) != setFrom.end())
				{
					return true;
				}
				if (setTo.find(*it) == setTo.end())
				{
					setTo.insert(*it);
					queueTo.push_back(*it);
				}
			}
		}
		
		return false;

	}
};


int main(int argc, char const *argv[])
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);
	g.addEdge(3,4);

	while(1)
	{
		int from,to;
		cin >> from >> to;

		if (g.bidirectionalBFS(from,to))
		{
			cout << "Path exist" << endl;
		}
		else
		{
			cout << "Path do not exist " << endl;
		}
		
	}



	return 0;
}