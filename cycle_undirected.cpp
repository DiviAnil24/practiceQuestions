#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;    
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    adj[w].push_back(v);
}
 

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	visited[v]=true;
	list<int>:: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
		{
			if(isCyclicUtil(*i,visited,v));
		}
		else if(*i!=parent)
		{
			return true;
		}
	}
	return false;

}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
 bool *visited= new bool[V];
 for(int j=0;j<V;j++)
 {
 	visited[j]=false;
 }
 for(int u=0;u<V;u++)
 {
 	if(!visited[u])
 	{
 		if(isCyclicUtil(u,visited,-1))
 		{
 			return true;
		 }
	 }
 }
 return false;
}
 
// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}
