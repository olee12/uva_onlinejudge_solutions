#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<iterator>
#include<cstring>
#include<map>
using namespace std;
map<string,int> visited;
map<string,string> root;
map<string,vector<string> > graph;
void bfsQ(string start,string to)
{
    queue<string>Q;
    Q.push(to);
    visited[to]=1;
    string tmp;
    string n;
    while(!Q.empty())
    {
        tmp=Q.front();
        int sz=graph[tmp].size();
        for(int i = 0; i<sz; i++)
        {
            n = graph[tmp][i];
            if(!visited[n])
            {
                root[n]=tmp;
                if(n==start)
                {
                    return;
                }
                visited[n]=1;
                Q.push(n);

            }
        }
        Q.pop();
    }
}
int main()
{
    int edges;
    int i,j=0,k,l;
    while(scanf("%d",&edges)!=EOF)
    {
        string s1,s2,start,to;
        root.clear();
        visited.clear();
        graph.clear();
        for(i=0; i<edges; i++)
        {
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
        }
        /* for(map<string,vector<string> > :: iterator it=graph.begin();it!=graph.end();it++){
             cout<<it->first<<" :";
             for(int i = 0;i< it->second.size();i++){
                 cout<<" "<< it->second[i];
             }
             cout<<endl;
         }
         puts("");*/
        cin>>start>>to;
        bfsQ(start,to);
        if(j)printf("\n");
        j=1;
        if(root[start]=="")
        {
            printf("No route\n");
            continue;
        }
        /*  for(map<string,string>::iterator it=root.begin();it!=root.end();it++){
              cout<<it->first<<' '<<it->second<<"\n";
          }*/
        while(start!=to)
        {
            cout<<start<<' '<<root[start]<<endl;
            start=root[start];
        }
    }
    return 0;
}



/*
this code is eating submission error;


#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;
map<string,int> visited;
map<string,string> root;
int bfsQ(string start,string to,map<string,vector<string> > &graph);

void display(string a,string b)
{
    if(a==b) return ;
    display(root[a],b);
    cout<<root[a]<<" "<<a<<endl;
}
int main()
{

    int edges;
    int i,j,d,k;

    int f=0;
    while(scanf("%d",&edges)!=EOF)
    {

        string start,to;
        string x,y;
        map<string,vector<string> >graph;

        for(i=0; i<edges; i++)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            visited[x]=-1;
            visited[y]=-1;
        }
        cin>>start>>to;
        if(f) printf("\n");
        f=1;
        if(bfsQ(start,to,graph)!=-1)
        {
            display(to,start);
        }
        else printf("No route\n");
    }
    return 0;
}
int bfsQ(string start,string to,map<string,vector<string> > &graph)
{

    queue<string> Q;
    Q.push(start);
    visited[start]=1;
    while(!Q.empty())
    {
        string top = Q.front();
        Q.pop();
        if(top==to) return visited[top];
        int sz=graph[top].size();
        for(int i=0; i<sz; i++)
        {
            string n=graph[top][i];
            if(visited[n]==-1)
            {
                visited[n]=visited[top]+1;

                root[n]= top;
                Q.push(n);

            }
        }
    }
    return -1;
}*/
