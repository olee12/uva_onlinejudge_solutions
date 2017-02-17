#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
#include<queue>
#define M 250
using namespace std;
int colour[M];
int part[M];

int bfstest(int x, vector<int>edge[],int N);
int main()
{
    int N,E,i;
    int x,y;
    while(cin>>N && N)
    {
        cin>>E;
        vector<int>edge[E+1];
        for(i=1; i<=E; i++)
        {
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        if(bfstest(x,edge,N)) cout<<"BICOLORABLE.\n";


    }
    return 0;
}

int bfstest(int x, vector<int>edge[],int N)
{


    for(int i=0; i<N; i++) colour[i]=part[i]=0;
    colour[x]=part[x]=1;
    queue<int >Q;
    Q.push(x);
    while(!Q.empty())
    {
        int u = Q.front();
        int vs=edge[u].size();
        for(int j=0; j<vs; j++)
        {
            int v = edge[u][j];
            if(part[u]==part[v])
            {

                cout<<"NOT BICOLORABLE.\n";
                return 0;
            }
            if(!colour[v])
            {
                colour[v]=1;
                part[v]= 3-part[u];
                Q.push(v);
            }
        }
        Q.pop();
    }
    return 1;
}
