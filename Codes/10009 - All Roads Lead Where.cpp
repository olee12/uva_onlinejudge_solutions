#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<iterator>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
map<string,vector<string> > graph;
map<string , int > visited;
map<string,string> root;
void bfsQ(string start,string to)
{
    queue<string> Q;
    Q.push(to);
    string top;
    string n;
    visited[to]=1;
    while(!Q.empty())
    {
        top=Q.front();
        int sz = graph[top].size();
        for(int i =0 ; i < sz; i++ )
        {
            n = graph[top][i];
            if(!visited[n])
            {
                visited[n]=1;
                Q.push(n);
                root[n]=top;
                if(n == start ) return;
            }
        }
        Q.pop();
    }
}

int main()
{
    int test;
    int edges;
    int pair;
    string s1,s2;
    scanf("%d",&test);
    while(test--)
    {
        cin.ignore();
        graph.clear();
        scanf("%d %d",&edges,&pair);
        for(int i = 0; i<edges; i++)
        {
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
        }
        for(int i = 0; i < pair; i++ )
        {
            cin>>s1>>s2;
            root.clear();
            visited.clear();

            bfsQ(s1,s2);


            while(s1!=s2)
            {
                cout<<s1[0];
                s1=root[s1];
            }
            cout<<s2[0]<<endl;


        }
        if(test) puts("");
    }
    return 0;


}
