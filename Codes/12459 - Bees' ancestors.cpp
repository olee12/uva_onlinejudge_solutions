#include<cstdio>
long long int ara[150];

int main()
{
    ara[0]=1;
    ara[1]=1;
    for(int i=2;i<=85;i++) ara[i]=ara[i-1]+ara[i-2];
    for(int j;scanf("%d",&j)==1 && j;printf("%lld\n",ara[j]));
    return 0;
}
