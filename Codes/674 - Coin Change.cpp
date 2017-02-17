#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 7490
unsigned long long nway[MAX+1];
int coin[5]={50,25,10,5,1};
int main()
{
    int i,j,n,v,c;

        v=5;
        nway[0]=1;
        for(i=0;i<v;i++){
            c = coin[i];
            for(j=c;j<=MAX;j++){
                nway[j] +=nway[j-c];
            }
        }

    while(scanf("%d",&n)==1){
        printf("%lld\n",nway[n]);
    }
    return 0;
}
/*
#include<stdio.h>
#define M 30000
long long ways[M+2];

int main()
{
    int coin[]={50,25,10,5,1};
    register int i,j,t;


    ways[0]=1;
    for(i=0;i<5;i++)
        for(j=coin[i];j<=M;j++)
            ways[j]+=ways[j-coin[i]];

    while(scanf("%ld",&t)==1)
    {

    }
    return 0;
}
*/
