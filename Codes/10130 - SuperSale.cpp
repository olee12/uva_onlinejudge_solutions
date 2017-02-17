#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int t,N,V[1050],W[1050],g,people[105],MW[105];
    int c[1005][105];
    scanf("%d",&t);
    while(t--)
    {
        cin>>N;
        for(int i = 1; i<=N; i++) cin>>V[i]>>W[i];
        cin>>g;
        for(int i= 0; i<g; i++) cin>>MW[i];
        for(int i = 0; i<=N; i++) c[i][0]=0;
        int man=0;
        int sum=0;
        int w;
        int x;
        for(man=0; man<g; man++)
        {
            for(x=0; x<=MW[man]; x++) c[0][x]=0;
            for(int i = 1; i<=N; i++)
            {
                for(w = 1; w<=MW[man]; w++)
                {
                    if(W[i]>w) c[i][w]=c[i-1][w];
                    else c[i][w] = max(c[i-1][w],c[i-1][w-W[i]]+V[i]);
                }
            }
            sum+=c[N][MW[man]];
        }
        cout<<sum<<endl;
    }
    return 0;
}
