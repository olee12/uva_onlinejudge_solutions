#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<iterator>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

map<int,int>root;
map<int,vector<int> > graph;
int bfsQ(int start,int& boom,int& day)
{
    map<int,int> visited;
    int current=0;
    int previous=0;
    int flag=0;
    int b=0,d=0;
    boom=0,day=0;
    queue<int> Q;
    Q.push(start);
    int disten[2505];
    disten[start]=0;
    visited[start]=1;
    int top,n;
    while(!Q.empty())
    {
        top = Q.front();
        Q.pop();
        previous=current;
        current=disten[top];
        if(previous<current) b=0;
        int sz = graph[top].size();
        for(int i =0; i<sz; i++)
        {
            n = graph[top][i];
            if(!visited[n])
            {
                b++;
                disten[n]=disten[top]+1;
                visited[n]=1;
                Q.push(n);
            }
        }
        if(boom<b)
        {
            boom=b;
            day = disten[top]+1;
            flag=1;
        }
    }
    return flag;
    for(int i = 0; i<6; i++)
    {
        printf("%d to %d is %d\n",start,i,disten[i]);
    }

}
int main()
{
    int E,i,j,k,l,x,y,num;
    scanf("%d",&E);
    for(i= 0; i<E; i++)
    {
        scanf("%d",&num);
        graph[i];
        for(j=0; j<num; j++)
        {
            scanf("%d",&x);
            graph[i].push_back(x);
            //graph[x].push_back(i);
        }
    }
    int test;
    int s;
    int boom,day;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&s);

        int res = bfsQ(s,boom,day);
        if(!res)
            printf("0\n");
        else
        {
            printf("%d %d\n",boom,day);
        }
    }


    return 0;

}
