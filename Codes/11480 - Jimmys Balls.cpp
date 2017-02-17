#include<stdio.h>
int main()
{

    int n;
    int cas = 1;
    while(scanf("%d",&n) && n)
    {
        register long long cnt = 0;
        register long long r,b,g;
        b = (n/3)-1;
        for(r = 1; r<=b; r++) cnt += (n - (3*r) - 1)/2;
        printf("Case %d: ",cas++);
        printf("%lld\n",cnt);
    }
    return 0;
}
