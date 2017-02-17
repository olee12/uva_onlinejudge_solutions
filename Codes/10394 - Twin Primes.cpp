#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<cstdio>
#include<queue>
#include<iterator>
using namespace std;
#define MAX 20000000
bool flag[MAX];
int prime[9000000];
int c;
void sieve()
{
   register int i,j,k,l,add;
    for(i=4; i<MAX; i+=2) flag[i]=1;
    for(i=3; i<MAX; i+=2)
    {
        if(!flag[i])
        {

            if(MAX/i>i)
            {
                add=i*2;
                for(j=i*i; j<MAX; j+=add) flag[j]=1;
            }
        }
    }
}
void twin()
{
    int j=1;
    for(int i = 3;i<MAX;i+=2){
        if(!flag[i] && !flag[i+2]){
            prime[j++]=i;
        }
    }
}
int main()
{
    sieve();
    twin();
    int i = 0;
    int j=0;
    int pos;
    while(scanf("%d",&pos)!=EOF)
    {
        printf("(%d, %d)\n",prime[pos],prime[pos]+2);
    }
    return 0;
}
