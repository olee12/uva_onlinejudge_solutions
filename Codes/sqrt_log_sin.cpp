#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define sf scanf
#define pf printf 
#define mem(a,b) memset(a,b,sizeof a)
int dp[1000005];
const int md = 1000000;
int func(int i)
 {
    if(i==0) return 1;
    int &res = dp[i];
    if(res!=-1) return res;
     res = ((func(     floor(i - double(sqrt(i)))   ) % md) + (func((int)log(i)) % md )+ (func( floor(i * sin(i) * sin(i)) )% md))%md;
    return res = res%md;

}
int main()
{
   mem(dp,-1);
    int a;
    while(sf("%d",&a) && a!= -1)
{
        pf("%d\n",func(a));
}
 return 0;  
}