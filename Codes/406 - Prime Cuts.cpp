#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
#define MAX 1003
bool flag[MAX];
int prime[MAX];
int cnt;
void sieve()
{
    prime[cnt++]=1;
    prime[cnt++]=2;
    int i,j,k,add;
    for(i=4; i<MAX; i+=2) flag[i]=1;
    for(int i=3; i<MAX; i+=2)
    {
        if(!flag[i])
        {
            prime[cnt++]=i;
            if(MAX/i>i)
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
    int N,C,i,j,k=0,l,lo,hi;

    while(cin>>N>>C)
    {

        k=1;
        cout<<N<<" "<<C<<":";
        for(i=0,j=0; prime[i]<=N && i<169; i++,j++);

        if(!(j%2))
        {

            if((C*2)>j)
            {
                for(i = 0; prime[i]<=N && i<169; i++)
                    cout<<" "<<prime[i];
            }
            else
            {
                lo=j/2 - (C-1);
                hi = j/2 + C;
                for(i = lo-1; i<hi; i++) cout<<" "<<prime[i];
            }
        }
        else
        {
            if((C*2 -1)> j)
            {
                for(i = 0; prime[i]<=N && i<169; i++)
                    cout<<" "<<prime[i];
            }
            else
            {
                lo = ceil(j/2.)-(C-1);
                hi = ceil(j/2.)+(C-1);
                for( i =lo-1; i<hi; i++) cout<<" "<<prime[i];
            }
        }
        printf("\n\n");
    }
    return 0;
}
