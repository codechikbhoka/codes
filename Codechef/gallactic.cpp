// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <map>
 
using namespace std;
 
 map<int, int> TaxMap;

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    

public:
    bool *visited;
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s, int& mintax);  // prints BFS traversal from a given source s and stores the min tax in its component in mintax
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s, int& mintax)
{
    // Mark all the vertices as not visited
    // bool *visited = new bool[V];
    // for(int i = 0; i < V; i++)
    //     visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        if (TaxMap[s] >=0 && mintax >= TaxMap[s])
        {
            mintax = TaxMap[s];
        }
        //cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    int N, M, a, b, k, curTax, p, d=0,flag=10, minall =20000;
    long long int answer=0;
    cin >> N;
    cin >> M;
    // Create a graph given in the above diagram
    Graph g(N);

    for (int i = 0; i < M; ++i)
    {
        cin >> a;
        a--;
        cin >> b;
        b--;
        g.addEdge(a,b);
        g.addEdge(b,a);
    }
    
    //g.BFS(2);

    for (int i = 0; i < N; ++i)
    {
        cin >> curTax;
        TaxMap[i] = curTax;
    }

    // while(!completelyvisited(g.visited, N))
    for (int i = 0; i < N; ++i)
    {
        if(g.visited[i] == false)
        {
            p=20000;
            g.BFS(i, p);
            //cout<<"p is "<<p<<endl;
            if (p==20000)
            {
                answer = -1;
                flag = 5;
                break;
            }
            else
            { 
                 answer = answer + p;
                 if (p <= minall)
                 {
                     minall = p;
                 }
            }

            d++;
       
        }
    }
    
    
    if (d==1 && flag==10)
    {
        cout<<"0"<<endl;
    }
    else if(d == 0 && flag==5)
    {
        cout<<"0"<<endl;
    }
    else
    {
        if (flag == 10)
        {
            answer = answer + (minall*(d-2));
        }
        
        cout<<answer<<endl;
    }

    return 0;
}
