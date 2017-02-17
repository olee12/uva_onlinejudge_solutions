#include<bits/stdc++.h>
using namespace std;
#define M 25145
char dic[M][18];
int graph[M][18],adjsz[M],root[M],N,length[M];
int visited[M];
int find_gra(string s)
{
    for(int i = 0; i<N; i++) if(s==dic[i]) return i;
    return -1;
}
bool ok(char s1[],char s2[])
{
    int k = 0;
    for(int i = 0; s1[i]; i++)
    {
        if(s1[i]^s2[i]) k++;
    }
    return k<=1;
}
bool bfs(int start,int to)
{
    queue<int > Q;
    Q.push(start);
    int u,v;
    visited[start]=1;
    while(Q.empty()==0)
    {
        u = Q.front();
        Q.pop();
        for(int i= 0; i<adjsz[u]; i++)
        {
            v = graph[u][i];
            if(!visited[v])
            {
                visited[v]=1;
                Q.push(v);
                root[v]=u;
                if(v==to) return true;
            }

        }
    }
    return false;
}
void display(int start,int to)
{
    if(start==to)
    {
        printf("%s\n",dic[start]);
        return ;
    }
    display(start,root[to]);
    printf("%s\n",dic[to]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char u[20],v[20];
    int l;
    bool flag =0,f=0;
    int i,j;
    while(gets(dic[N]),dic[N][0]!='\0')
    {
        for(l=0; dic[N][l]; l++);
        length[N]=l;
        N++;
    }
    for(i = 0; i<N; i++)
    {
        for(j = i+1; j<N; j++)
        {
            if(length[i]==length[j] && ok(dic[i],dic[j]))
            {
                //cout<<i<<' '<<j<<endl;
                graph[i][adjsz[i]++]=j;
                graph[j][adjsz[j]++]=i;
            }
        }
    }
    while(scanf("%s %s",u,v)==2)
    {
        int from = find_gra(u);
        int to = find_gra(v);
      //  cout<<from<<' '<<to<<endl;

        if(f) puts("");
        f=1;
        if(length[from]!=length[to])
        {
            printf("No solution.\n");
            continue;
        }
        if(bfs(from,to))
        {
            display(from,to);
        }
        else
        {
            printf("No solution.\n");
        }
        memset(visited,0,sizeof visited);
    }
    return 0;
}

