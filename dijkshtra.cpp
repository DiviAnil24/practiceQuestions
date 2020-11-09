#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector< pair <int,int> > v[],int V,int E,int src)
{
	 priority_queue< pair<int,int>, vector < pair<int,int> > , greater< pair<int,int > > > pq;
	 int dist[V],i;
	 for(i=0;i<V;i++)
	 {
	 	dist[i]=INT_MAX;
	 }
	 dist[src]=0;
	 pq.push(make_pair(0,src));
	 while(!pq.empty())
	 {
	 	int u=pq.top().second;
	 	pq.pop();
	    vector< pair<int , int> >::iterator it;
	 	for(it=v[u].begin(); it!=v[u].end();it++)
	 	{
	 		int dest=(*it).first;
	 		int wt=(*it).second;
	 		if(dist[dest]>dist[u]+wt)
	 		{
	 			dist[dest]=dist[u]+wt;
	 			pq.push(make_pair(dist[dest],dest));
			}
			
		}
	 	
	 }
	 for(int i=0;i<V;i++)
	 {
	 	cout << dist[i] << " ";
	 }
	 
}
int main()
{
	int V,E;
	cin >> V >> E;
	vector< pair <int,int> > v[V];
	int a,b,c,i;
	for(i=0;i<E;i++)
	{
		cin >>a >> b>> c;
		v[a].push_back(make_pair(b,c));
	}
	dijkstra(v,V,E,0);
}
