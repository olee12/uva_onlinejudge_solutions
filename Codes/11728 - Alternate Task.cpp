#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int ara[1010];
void func()
{
    for(int i = 1; i<=1005; i++)
    {
        int sum = 0;
        for(int j = 1; j<=i; j++)
        {
            if(i%j==0) sum+=j;
        }
        ara[i-1]=sum;
    }
}
int main()
{
    func();
    int cas = 1;
    int num ;
    while(scanf("%d",&num) && num )
    {
        bool flag = false;
        int i;
        for(i = 1005; i>=0; i--)
        {
            if(ara[i]==num)
            {
                flag = true;
                break;
            }
        }
        if(flag) printf("Case %d: %d\n",cas++,i+1);
        else printf("Case %d: -1\n",cas++);
    }
    return 0;
}
