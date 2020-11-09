#include<bits/stdc++.h>
using namespace std;
void Bellman(vector<pair<pair<int,int>,int> >v,int V,int E)
{
	int i,j;
	int dist[V];
	for(i=1;i<V;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	for(i=0;i<V-1;i++)
	{
		for(j=0;j<E;j++)
		{
			int src=v[j].first.first;
			int dest=v[j].first.second;
			int wt=v[j].second;
			if(dist[src]!=INT_MAX && dist[dest]>dist[src]+wt)
			{
				dist[dest]=dist[src]+wt;
			}
		}
	}
	for(i=0;i<V;i++)
	{
		cout << dist[i] << " ";
	}
}
int main()
{
	int V,E;
	cin>>V>>E;
	vector< pair< pair<int,int>,int > > v;
	int i,a,b,c;
	for(i=0;i<E;i++)
	{
		cin>>a>>b>>c;
		v.push_back(make_pair(make_pair(a,b),c));
		
	}
	Bellman(v,V,E);
	return 0;
}

