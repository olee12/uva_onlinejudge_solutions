#include<cstring>
#include<iostream>
#include<cstdio>
#include<limits.h>
#include<map>
#include<set>
#include<stack>
#include<vector>
#define NINF INT_MIN
using namespace std;
// Class to represent a graph using adjacency list representation
struct graph
{
    int V; // No. of vertices’
    int pos=0;
    int sum=0;
    graph(int V);
    map<int,set<int> > edge;
    // A function used by longestPath
    void topologicalSortUtil(int u,bool visited[],stack<int> &s);
    // function to add an edge to graph
    void addEdge(int u,int v);
    // Finds longest distances from given source vertex
    void longestPath(int s);
};
graph::graph(int V)
{
    this->V=V;
}
void graph::addEdge(int u,int v)
{
    edge[u].insert(v);// Add v to u’s list
}
// A recursive function used by longestPath. See below link for details
void graph::topologicalSortUtil(int u,bool visited[],stack<int> &s)
{
    // Mark the current node as visited
    visited[u]=true;
    // Recur for all the vertices adjacent to this vertex
    set<int> :: iterator it;
    for(it=edge[u].begin(); it!=edge[u].end(); it++)
    {
        if(visited[*it]==0) topologicalSortUtil(*it,visited,s);
    }
    // Push current vertex to stack which stores topological sort
    s.push(u);
}
// The function to find longest distances from a given vertex. It uses
// recursive topologicalSortUtil() to get topological sorting.
void graph::longestPath(int s)
{
    stack<int> st;
    int dist[V+1];

    bool *visited = new bool[V+1];
    // Mark all the vertices as not visited
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for(int i = 1; i<=V; i++) visited[i] = false;
    for(int i = 1; i<=V; i++)
    {
        if(visited[i]==false) topologicalSortUtil(i,visited,st);
    }

    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for(int i = 1; i<=V; i++) dist[i]=NINF;
    dist[s]=0;
    // Process vertices in topological order
    while(st.empty()==false)
    {
        // Get the next vertex from topological order
        int u = st.top();
        st.pop();
        // Update distances of all adjacent vertices
        set<int> :: iterator it;
        if(dist[u]!=NINF)
        {
            for(it = edge[u].begin(); it!=edge[u].end(); it++)
            {
                if(dist[*it] < (dist[u]+1))
                    dist[*it]=dist[u]+1;
            }
        }
    }
    // Print the calculated longest distances
    for(int i = 1; i<=V; i++)
    {
        if(dist[i]>sum)
        {
            pos=i;
            sum = dist[i];
        }
    }

}
// Driver program to test above functions
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n,u,v,s;
    int cas=1;
    while(scanf("%d",&n))
    {
        graph g(n);
        if(n==0) break;
        scanf("%d",&s);
        while(scanf("%d %d",&u,&v))
        {
            if(u==0 && v==0) break;
            g.addEdge(u,v);
        }
        g.longestPath(s);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",cas++,s,g.sum,g.pos);
        puts("");
    }
    return 0;
}
