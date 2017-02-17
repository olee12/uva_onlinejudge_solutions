#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 30000
long long nway[MAX+2];
int coin[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int main()
{
    int i,j,c,v,n1,n2;
    v=11;
    nway[0]=1;
    for(i=0;i<v;i++){
        c=coin[i];
        for(j=c;j<=MAX;j++){
            nway[j] += nway[j-c];
        }
    }
    int x;
    scanf("%d.%d",&n1,&n2);
    while(n1||n2)
    {
        x = n1*100 + n2;
        printf("%3d.%.2d%17lld\n",n1,n2,nway[x]);
        scanf("%d.%d",&n1,&n2);
    }
    return 0;
}
