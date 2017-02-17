#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define M 1000000
bool flag[M];
bool skr[10005];
int c;
int prime[M];
void sieve()
{
    register int i,j,add;
    prime[c++]=2;
    int sqrtN = sqrt(M);
    for(i = 4; i<M; i+=2) flag[i]=true;
    for(i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(i<=sqrtN)
            {
                add = i<<1;
                for(j = i*i; j<M; j+=add) flag[j]=true;
            }
        }
    }
}
bool isprime(int n)
{
    if(n<M) return (flag[n]==false);
    int i = 0;
    while(prime[i]*prime[i] <= n)
    {
        if(n%prime[i] == 0) return false;
        i++;
    }
    return true;
}
int main()
{
    sieve();
    int cnt = 0;
    //for(int i = 0;i<100;i++) printf(" %d ",prime[i]);
    for(int i = 0; i<=10000; i++)
    {
        int num = i*i+i+41;
       if(isprime(num)) skr[i]=true;

    }
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        for(int i = a;i<=b;i++){
            if(skr[i]) cnt++;
        }
        printf("%.2lf\n",(double)(cnt*100)/(b-a+1) + 1e-9);
        cnt=0;

    }
    return 0;

}
