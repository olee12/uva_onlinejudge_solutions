#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define M 100050000
bool flag[M];
int prime[M];
void sieve()
{
    flag[0]=true;
    flag[1]=true;
    flag[2]=false;
    register int i,j,add;
    for(i = 4; i<M; i+=2) flag[i]=true;
    for(i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {

            if(M/i >=i)
            {
                add = i*2;
                for(j = i*i; j<M; j+=add) flag[j]= true;

            }
        }
    }
}
int smm(int j)
{
    int sum = 0;
    while(j!=0)
    {
        sum+=(j%10);
        j/=10;
    }
    return sum;
}
void func()
{
    register int i,j,k,sum;
    int cnt = 0;
    for(int i = 1; i<M; i++)
    {
        sum = smm(i);

        if(flag[sum]==false && flag[i]==false)
        {
            cnt++;
        }
        prime[i]=cnt;

    }
}
int main()
{
    sieve();
    func();
    int test;
    int t1,t2;
    int sum;
    int cnt = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&t1,&t2);
        cnt = prime[t2]-prime[t1];
        if(flag[t1]==0 && flag[smm(t1)]==0) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
