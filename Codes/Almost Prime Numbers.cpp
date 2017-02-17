#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
#define MAX 1000010
#define LIM 10000010
bool flag[MAX];
int c;

void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    flag[3]=0;
    int add;
    for(int i = 4; i<MAX; i+=2) flag[i]=1;
    for(int i = 3; i<MAX; i++)
    {
        if(!flag[i])
        {

            if(MAX/i>=i)
            {
                add = i*2;
                for(int j = i*i; j<MAX; j+=add) flag[j]=1;
            }
        }
    }
}


int main()
{
    sieve();


    long long  int almostprime[100000];
    int c=0;
    long long int hi,lo;

    int test;
    register long long int i,j;
    for(i=4; i<=1000000000000; i*=2)
        almostprime[c++]=i;

    for(i=3; i<=1000000; i+=2)
    {
        if(!flag[i])
        {
            for(j=i*i; j<=1000000000000; j*=i)
                almostprime[c++]=j;
        }
    }
    sort(almostprime,almostprime+c);
    scanf("%d",&test);
    int num;
    while(test--)
    {
        scanf("%lld %lld",&lo,&hi);
        num=0;
        for(i= 0;almostprime[i]<=hi; i++)
        {
            if(almostprime[i] >=lo && almostprime[i]<=hi )
                num++;
        }
        printf("%d\n",num);

    }
    return 0;

}
