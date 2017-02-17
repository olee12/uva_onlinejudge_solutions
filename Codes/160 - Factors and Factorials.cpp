#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iterator>
#include<sstream>
#include<map>
using namespace std;
#define MAX 150
bool flag[MAX];
int prime[MAX];
int c;
void sieve()
{
    int i,j,k,l,add;
    prime[c++]=2;
    for(i=4; i<MAX; i+=2) flag[i]=1;
    for(i=3; i<MAX; i+=2)
    {
        if(!flag[i])
        {
            prime[c++]=i;
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
    int fac;
    int i,j,k,l,m;
    int num;
    while(cin>>fac && fac)
    {
        map<int,int> mp;
        for(num=fac; num>1; num--)
        {
            int a=num;
            for(i=0; prime[i]<100; i++)
            {
                while(a%prime[i]==0)
                {
                    mp[prime[i]]++;
                    a/=prime[i];
                }
            }
        }
        l = mp.size();
        printf("%3d! =",fac);
        for(i=0; i<l; i++)
        {
            if(i == 15) printf("\n%9d",mp[prime[i]]);
            else
                printf("%3d",mp[prime[i]]);
        }
        printf("\n");

    }
    return 0;
}
