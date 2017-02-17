#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define M 10005
bool flag[M];
int prime[M];
int c=1;
int save[M];
void sieve()
{
    prime[c++]=2;
    int add;
    int sq = sqrt(M);
    for(int i = 4;i<M;i+=2) flag[i]=true;
    for(int i = 3;i<M;i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(sq>=i)
            {
                add = i*2;
                for(int j = i*i;j<M;j+=add) flag[j]=true;
            }
        }
    }
}
int main()
{
    sieve();
    save[1]=2;
   // cout<<c<<endl;
    for(int i = 2;i<c;i++) save[i]=prime[i]+save[i-1];
    //for(int i = 0;i<50;i++) cout<<save[i]<<endl;
    int n;
    int cnt = 0;
    int sum;
    while(scanf("%d",&n),n)
    {
        cnt=0;
        if(flag[n]==0) cnt++;
        for(int i = 1;prime[i]<=n && i<c;i++)
        {
            for(int j = i+1;prime[j]<=n && j<c;j++)
            {
                sum = save[j]-save[i-1];
                if(sum==n) cnt++;
                if(sum>n) break;
                //cout<<i<<' '<<j<<' '<<sum<<endl;;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
