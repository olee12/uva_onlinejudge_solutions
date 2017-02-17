#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<queue>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;


map<int,int>visited;
map<int,int> root;
void display(int to,int start);
int  bfsQ(int start,int to,map<int,vector<int> >graph)
{
    queue<int> Q;
    Q.push(start);
    visited[start]=1;
    int top;
    int n;
    while( !Q.empty() )
    {
        top=Q.front();
        if(top==to)
        {
            return 1;
        }
        int sz=graph[top].size();
        for(int i = 0; i<sz; i++)
        {
            n = graph[top][i];
            if(!visited[n])
            {
                visited[n]=1;
                root[n]=top;


                Q.push(n);
            }
        }
        Q.pop();

    }
    return 0;
}
vector<int> inputvector(string s)
{
    vector<int> r;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ','))
    {
        r.push_back(atoi(tmp.c_str()));
    }
    return r;
}
int main()
{

    int N,M;
    int test;

    while(scanf("%d",&N)==1)
    {
        map<int,vector<int> > graph;
        string s;
        for (int i = 0; i <N; ++i)
        {
            cin>>s;
            int pos1 = s.find("-");
            graph[atoi(s.substr(0,pos1).c_str())] = inputvector(s.substr(pos1+1));

        }
        printf("-----\n");

        /* map<int ,vector<int> > :: iterator it;
         for(it=graph.begin(); it!=graph.end(); it++)
         {
             sort(it->second.begin(),it->second.end());
         }
        */
        int start,to;
        scanf("%d",&M);
        for(int i = 0; i<M; i++)
        {
            root.clear();
            visited.clear();
            cin>>start>>to;
            int res = bfsQ(start,to,graph);
            if(res)
            {
                display(to,start);

            }
            else
            {
                printf("connection impossible");
            }
            printf("\n");
        }
    }
    return 0;
}
void display(int to,int start)
{
    if(start==to)
    {
        printf("%d",start);
        return;
    }
    display(root[to],start);
    printf(" %d",to);
}
