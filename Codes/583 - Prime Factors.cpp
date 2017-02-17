#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define MAX 46340
#define LIM 5000
using namespace std;
bool flag[MAX];
int prime[LIM];
int c;
int main()
{
    prime[c++]=2;
   register int i,j,add;
    for(i=4; i <=  MAX; i+=2) flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {
        if(!flag[i])
        {
            prime[c++]=i;
            if(MAX/i>=i)
            {
                add=i<<1;
                for(j=i*i; j<=MAX; j+=add) flag[j]=1;
            }
        }
    }
    cout<<c;
    int num;
    int count;
    int lim;
    while(scanf("%d",&num)==1 && num)
    {
        printf("%d = ",num);
        lim=sqrt(abs(num));
        count=0;
        if(num<0) printf("-1"),count++;

        for(i=0; i<c && prime[i]<=lim; i++)
        {
            while(num%prime[i]==0)
            {
                if(count!=0)
                    printf(" x %d",prime[i]);
                else printf("%d",prime[i]),count++;
                num/=prime[i];
            }
        }
        if(abs(num)>1 && count>0) printf(" x %d",abs(num));
        else if(num>1) printf("%d",num);
        printf("\n");
    }
    return 0;


}
