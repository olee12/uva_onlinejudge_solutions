#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;

map<string,int> name;
int taken[100];
int cas = 1;
int dis;
int p;
bool comp(int i )
{
    return i==0;
}
void bfs(int start,set<int> graph[])
{

    int disten[100];
    queue<int> Q;
    int u,v;
    set<int> :: iterator it;
    memset(taken,0,sizeof taken);
    memset(disten,0,p+3);
    disten[start]=0;
    taken[start]=1;
    Q.push(start);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(it = graph[u].begin(); it!=graph[u].end(); it++)
        {
            v = *it;
            if(!taken[v])
            {
                taken[v]=1;
                // cout<<v<<endl;
                dis = disten[v]= disten[u]+1;
                Q.push(v);
            }
        }
    }
    //int m = 0;
    //for(int i = 0;i<p;i++) if(disten[i]>m) m = disten[i];
   // dis = m;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,l,r,q;
    char inp[1000];
    char str1[1000],str2[1000];

    int x ,y;
    int cas=1;
    while(scanf("%d %d",&q,&r)==2)
    {
        if(q==0 && r==0) break;
        set<int> graph[100];
        p = 1;
        for(i=0; i<r; i++)
        {

            scanf(" %s %s",str1,str2);

            if(name.find(str1)==name.end())
            {

                name[str1]=p++;
            }
            if(name.find(str2)==name.end())
            {

                name[str2]=p++;
            }
            x = name[str1];
            y = name[str2];
            graph[x].insert(y);
            graph[y].insert(x);
        }
        name.clear();

        /*for(int i = 1; i<p; i++)
        {
            set<int>:: iterator it;
            cout<<i<<" :";
            for(it=graph[i].begin(); it!=graph[i].end(); it++)
            {
                cout<<' '<<*it;
            }
            cout<<endl;
        }*/
        int co;
        int maa=0;
        for(int i = 1;i<p;i++){
        bfs(i,graph);
         co = count_if(taken,taken+p,comp);
        if(co>1) break;
        if(dis>maa) maa = dis;
        }
        //cout<<p<<endl;

    if(co==1 && q == p-1) printf("Network %d: %d\n",cas++,maa);
    else printf("Network %d: DISCONNECTED\n",cas++);
    printf("\n");




    }
    return 0;
}



