#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
#define MAX 100
bool flag[MAX];
//int prime[MAX];
int c;
void sieve()
{
    int i,j,k,l,add;
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    //prime[c++]=2;
    for(i=4; i<MAX; i+=2) flag[i]=1;
    for(i=3; i<MAX; i+=2)
    {
        if(!flag[i])
        {
            //  prime[c++]=i;
            if(MAX/i>=i)
            {
                add = i*2;
                for(j=i*i; j<MAX; j+=add) flag[j]=1;

            }
        }
    }
}

int main()
{
    sieve();
    long long  int L,H,t,count_prime;
   long long int root;
    int div;
    long long int i,j,k;
    int f=0;
    int index;
    int take;
   long long int ara[5000];
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%lld %lld",&L,&H);
            index=0;
            for(i = L ; i <= H ; i++)
            {
                /*if(!flag[i])
                {
                    ara[index++]=i;
                    continue;
                }*/
                div=0;
                root = sqrt(i);
                for(j=1; j<=root; j++)
                {
                    if(i%j==0)
                    {
                        div++;
                        if(i/j != j) div++;
                    }
                }
                if(!flag[div]) ara[index++]=i;

            }
            if(index>0)
            {
                printf("%lld",ara[0]);
                for(i=1; i<index; i++) printf(" %lld",ara[i]);
                printf("\n");
            }
            else printf("-1\n");
        }
    }
    return 0;
}
