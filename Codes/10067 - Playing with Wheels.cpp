#include <cstring>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define M 10001
#define mem(a) memset(a,0,sizeof(a))
bool lock[M];
int dir[8][4]=
{
    {0,0,0,1},
    {0,0,0,-1},
    {0,0,1,0},
    {0,0,-1,0},
    {0,1,0,0},
    {0,-1,0,0},
    {1,0,0,0},
    {-1,0,0,0}
};
int to;
int bfs(int a,int b,int c,int d)
{
    int tmp1,tmp2;
    queue<int> Q;
    tmp1 = a*1000+100*b+c*10+d;
    if(tmp1==to) return 0;
    Q.push(a);
    Q.push(b);
    Q.push(c);
    Q.push(d);
    int dist[M];
    mem(dist);
    dist[tmp1]=0;
    int ta,tb,tc,td;
    int sa,sb,sc,sd;
    while(Q.empty()==false)
    {
        sa = Q.front();
        Q.pop();
        sb=Q.front();
        Q.pop();
        sc=Q.front();
        Q.pop();
        sd=Q.front();
        Q.pop();
        tmp1 = sa*1000+100*sb+sc*10+sd;
        if(tmp1==to) return dist[to];
        for(int i = 0; i<8; i++)
        {
            ta = sa+dir[i][0];
            tb = sb+dir[i][1];
            tc = sc+dir[i][2];
            td = sd+dir[i][3];
            if(ta>9) ta = 0;
            if(ta<0) ta = 9;
            if(tb>9) tb = 0;
            if(tb<0) tb = 9;
            if(tc>9) tc = 0;
            if(tc<0) tc = 9;
            if(td>9) td = 0;
            if(td<0) td = 9;

            tmp2 = ta*1000+100*tb+10*tc+td;
            if(lock[tmp2]==true) continue;
            lock[tmp2]=true;
            dist[tmp2] = dist[tmp1]+1;
            Q.push(ta);
            Q.push(tb);
            Q.push(tc);
            Q.push(td);
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int sa,sb,sc,sd;
    int ta,tb,tc,td;
    int a,b,c,d;
    int test;
    int n;
    int tmp;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d %d",&sa,&sb,&sc,&sd);
        scanf("%d %d %d %d",&ta,&tb,&tc,&td);
        to = 1000*ta+100*tb+10*tc+td;
        scanf("%d",&n);
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            // cout<<a<<b<<c<<d<<endl;
            tmp = 1000*a+100*b+10*c+d;
            lock[tmp]=true;
        }
        int res = bfs(sa,sb,sc,sd);
        cout<<res<<endl;
        mem(lock);

    }
    return 0;
}

