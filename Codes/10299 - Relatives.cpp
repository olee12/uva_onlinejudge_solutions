#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
int phi(int n)
{
   if(n==1) return 0;
    int ret = n;
    if((n&1) ==0) {
        while((n&1)==0) n >>=1;
        ret -= ret/2;
    }
    for(int i = 3; i*i<=n; i+=2)
    {

        if(n%i==0)
        {
            while(n%i==0) n/=i;
            ret -= ret/i;
        }
    }
    if(n>1) ret-= ret/n;
    return ret;
}
int main()
{
    int  n;
    while(scanf("%d",&n),n)
    {
        printf("%d\n",phi(n));
    }
    return 0;
}

