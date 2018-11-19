/*
	Simulate and implement Dijkstra algorithm for shortest path routing
*/
#include<iostream>
using namespace std;

#define A 4
int minDistance(int dist[A],bool set[A])
{
	int min= INT_MAX,min_index;
	for(int i=0;i<A;i++)
	{
		if(set[i]==false && dist[i]<=min)
		{
			min=dist[i],min_index=i;
		}
	}
	return min_index;
}

void printPath(int parent[],int j)
{
	if(parent[j]==-1)
	{
		return;
	}
	printPath(parent,parent[j]);
	cout<<j;
}

void printSolution(int dist[],int n,int parent[])
{
	int src=0;
	cout<<"Vertex\t\tDistance\tPath";
	for(int i=1;i<A;i++)
	{
		cout<<"\n"<<src<<"->"<<i<<"\t\t"<<dist[i]<<"\t\t"<<src;
		printPath(parent,i);
	}
	cout<<"\n\n";
}

void dijkstra(int graph[A][A],int src)
{
	//output distance array
	int dist[A];
	//stores true if  i is included in the shotest path
	bool set[A];
	int parent[A];
	for(int i=0;i<A;i++)
	{
		parent[0]=-1;
		dist[i]=INT_MAX;
		set[i]=false;
	}
	dist[src]=0;
	for(int count=0;count<A-1;count++)
	{
		int u=minDistance(dist,set);
		set[u]=true;
		for(int i=0;i<A;i++)
		{
			if(!set[i]&&graph[u][i]&&dist[u]+graph[u][i]<dist[i])	
			{
				parent[i]=u;
				dist[i]=dist[u]+graph[u][i];
			}
		}
	}
	printSolution(dist,A,parent);
}

int main()
{
	int graph[A][A]={ {0,2,6,4}, {2,0,8,0}, {6,8,0,6}, {4,0,6,0} };
	dijkstra(graph,0);
	return 0;
}
