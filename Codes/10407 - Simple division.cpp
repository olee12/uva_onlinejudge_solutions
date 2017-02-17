#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#include<cmath>
int ara[1050];
int main()
{
    int a;
    int ind=0;
    int mn;
    while(scanf("%d",&a) && a)
    {
        ara[ind++]=a;
        while(scanf("%d",&a) && a)
        {
            ara[ind++]=a;
        }
        mn = (1<<31)-1;
        int gcd;
        for(int i=  0;i<ind;i++) mn = min(mn,ara[i]);
        for(int i=0;i<ind;i++ ) ara[i]-=mn;
        gcd = __gcd(ara[0],ara[1]);
        for(int i = 2;i<ind;i++) gcd = __gcd(gcd,ara[i]);
        printf("%d\n",gcd);
        ind = 0;
    }
    return 0;
}
