#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	public :
		Graph(int V);
		void addEdge(int v, int w);
		void DFS(int s); 
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
void Graph::DFS(int s)
{
   bool *visited =new bool[V];
   for(int i=0;i<V;i++)
   {
   	visited[i]=false;
   }
   list<int>stack;
   list<int>::iterator i;
   stack.push_back(s);
   visited[s]=true;
    cout << s << " ";
   while(!stack.empty())
   {
   	int flag=0;
   	s=stack.front();
   	for(i=adj[s].begin();i!=adj[s].end();i++)
   	{
   		if(visited[*i]==false)
   		{
   			flag=1;
   			stack.push_front(*i);
			visited[*i]=true;
			s=stack.front();
   			cout << s << " ";
			break;	
		}
	}
	if(flag==0)
	{
		stack.pop_front();
	}
   }
}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}
