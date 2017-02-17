#include<iostream>
#include<cstdio>
#include<vector>
#define MAX 1000000
using namespace std;
bool flag[MAX+2];
vector< int > prime;
void sieve()
{
       flag[0]=1;
flag[1]=1;
flag[2]=0;
    register int i,j,add;
    prime.push_back(2);
    for(i=4;i<=MAX;i+=2) flag[i]=1;
    for(i=3;i<=MAX;i+=2){
        if(!flag[i]){
            prime.push_back(i);
            if(MAX/i>i){
            add=i<<1;
            for(j=i*i;j<=MAX;j+=add) flag[j]=1;

        }
        }
    }
}
int main()
{
    sieve();

    int num,i,p2;
    while(scanf("%d",&num)&&num){
        p2=0;
        for(i= 0;flag[p2];i++){

            p2=num-prime[i];

        }
        printf("%d = %d + %d\n",num,prime[i-1],p2);
    }
    return 0;
}
