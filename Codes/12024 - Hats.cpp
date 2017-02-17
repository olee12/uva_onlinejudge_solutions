#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int d(int n);
int main()
{
    int n;
    int i;
    int ara[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
    int test;
    scanf("%d",&test);
    while(test--){
            scanf("%d",&n);
        printf("%d/%d\n",d(n),ara[n]);

    }
    return 0;
}
int d(int n)
{
    if(n==1)return 0;
    if(n==2) return 1;
    return ((n-1)*( d(n-1)+d(n-2) ));
}
