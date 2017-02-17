/*#include<iostream>
#include<cstdio>
#include<cstring>
#define M 30
using namespace std;

int graph[M][M],times,color[M],hv;
void DFS_Visit(int);

int main()
{
    char inp[5];
    int t,x,y,i;


    scanf("%d\n\n",&t);
    while(t--)
    {
        gets(inp);
        hv=inp[0]-65;
        cout<<hv<<endl;

        memset(graph,0,sizeof(graph));
        memset(color,0,sizeof(color));

        while(gets(inp))
        {
            for(i=0;inp[i];i++);
            if(!i)break;

            x=inp[0]-65,y=inp[1]-65;
            graph[x][y]=graph[y][x]=1;
        }

        times=0;
        for(i=0;i<=hv;i++)
        {
            if(color[i]==0)
            {
                DFS_Visit(i);
                times++;
            }
        }
        if(t)
            printf("%d\n\n",times);
        else
            printf("%d\n",times);
    }
    return 0;
}

void DFS_Visit(int u)
{
    int i;
    color[u]=1;
    for(i=0;i<=hv;i++)
        if(graph[u][i]&&color[i]==0)
            DFS_Visit(i);
    color[u]=2;
}*/
/*E
AB
CE
DB
EC*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<iterator>
#include<cstring>
#define M 35
using namespace std;
int colour[M];
int graph[M][M];
int hv;
void dfs(int u)
{
    int i ;
    colour[u]=1;
    for(i = 0;i<=hv;i++){
        if(graph[u][i]&&colour[i]==0){
            dfs(i);
        }
    }
    colour[u]=2;
}


int main()
{

    int t;
    int count;

    int x,y;

    int i;
    char inp[5];
    scanf("%d\n\n",&t);
    while(t--){
        gets(inp);
        memset(graph,0,sizeof(graph));
        memset(colour,0,sizeof(colour));
        hv=inp[0]-65;
        while(gets(inp)){
            for(i = 0;inp[i];i++);
            if(!i) break;
            x=inp[0]-65;y=inp[1]-65;
            graph[x][y]=graph[y][x]=1;
        }
        count=0;
        for( i = 0;i<=hv;i++){
            if(colour[i]==0){
                    dfs(i);
                count++;
            }
        }

        if(t) printf("%d\n\n",count);
        else printf("%d\n",count);
    }
    return 0;
}

/*
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int par[200];
int flag[200];
char find_par(char r)
{
    if(par[r]==0) return r;
    if(par[r]==r) return r;
    return par[r] = find_par(par[r]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;
    char ch;
    char u,v;
    char str[10];
    scanf("%d",&test);
    getchar();
    while(test--){
        scanf(" %c",&ch);
        //cout<<ch<<endl;
        gets(str);

       // getchar();
        while(gets(str)){
                if(str[0]=='\0') break;
                //cout<<str<<endl;
            u = find_par(str[0]);
            v = find_par(str[1]);
            if(u!=v) par[u]=v;
        }
        int cnnect=0;
        map<char ,int > ara;
        for(char i = 'A' ; i<=ch;i++){
                char a = find_par(i);
            if(!ara[a]){
                ara[a]=1;
                cnnect++;
            }
        }
        cout<<cnnect<<endl;
        if(test) puts("");
        memset(par,0,sizeof par);
    }
    return 0;
}
*/
