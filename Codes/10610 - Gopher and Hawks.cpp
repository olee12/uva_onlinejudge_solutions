#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<iterator>
#include<cmath>
using namespace std;
#define M 1005
typedef struct
{
    double x;
    double y;

} Hole;
Hole P[M];
double dis;
int N;
bool valid(Hole h1, Hole h2)
{
    double x,y, xy;
    x = h1.x-h2.x;
    y = h1.y - h2.y;
    xy = sqrt( x*x + y*y );
    if(xy + .00000001 > dis) return false;
    return true;
}
int bfsQ(Hole start,Hole to)
{
    queue<int> Q;
    Q.push(0);
    int visited[M]= {0};
    int disten[M];
    int top,n;
    visited[0]=1;
    disten[0]=0;
    while(!Q.empty())
    {
        top = Q.front();
        for(int i =0; i<N; i++)
        {
            if(!visited[i] && valid(P[top],P[i]))
            {
                visited[i]=1;
                disten[i]=disten[top]+1;
                if(P[i].x==to.x && P[i].y == to.y) return disten[top];
                Q.push(i);
                //  cout<<i;
            }
        }
        Q.pop();
    }
    return -1;
}
int main()
{
    int hole;
    int start;
    char str[1000];
    int v,m;
    int i,j,k,l;

    while(scanf("%d %d",&v,&m) && (m+v))
    {

        N=0;
        dis = 60.0*v*m;
        getchar();
        while(gets(str))
        {
            for(l = 0; str[l]; l++);
            if(!l) break;
            sscanf(str,"%lf %lf",&P[N].x,&P[N].y);

            N++;
        }
        /*  for(i=0;i<N;i++){
              cout<<P[i].x<<' '<<P[i].y<<endl;
          }*/
        int res = bfsQ(P[0],P[1]);
        if(res>=0)
            printf("Yes, visiting %d other holes.\n",res);
        else
            printf("No.\n");
    }
}
