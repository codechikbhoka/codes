#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    
public:
	int *parent;
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    parent = new int[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v list.
}


void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
            	parent[*i] = s;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
	int testcases;
	cin >> testcases;
	for (int i = 0; i < testcases; ++i)
	{
		int n, p , hq1, hq2;
		cin >> n;
		cin >> hq1;
		cin >> hq2;

		Graph g(n+1);
		for (int i = 1; i < hq1; ++i)
		{
			cin >> p;
			g.addEdge(i,p);
			g.addEdge(p, i);

		}
		for (int i = hq1 + 1; i <= n; ++i)
		{
			cin >> p;
			g.addEdge(i,p);
			g.addEdge(p, i);

		}

		g.BFS(hq2);

		int i;
		for (i = 1; i < hq2; ++i)
		{
				cout << g.parent[i] << ' ' ;	
		}
		for (i = (hq2+1); i <=n; ++i)
		{
				cout << g.parent[i] << ' ';
		}

		cout << endl;
	}
	
	return 0;
}