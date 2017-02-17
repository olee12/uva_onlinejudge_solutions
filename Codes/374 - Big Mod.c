#include<stdio.h>
int mpower(int b,int n,int m);
unsigned int powermod(int a, int n, int d);
int main()
{
    int b,m,n;
    while(scanf("%d %d %d",&b,&n,&m)==3){
        printf("%d\n",mpower(b,n,m));
        printf("%d\n",powermod(b,n,m));
    }
    return 0;
}
int mpower(int b,int n,int m)
{
    if(n==0) return 1;
    else if(!(n%2)) return ((mpower(b,n/2,m)*mpower(b,n/2,m))%m);
    else return ((((mpower(b,n/2,m)*mpower(b,n/2,m))%m)*(b%m))%m);
}
unsigned int powermod(int a, int n, int d)
{
    unsigned int x;

    if (n == 0)
        return 1;
    if (n == 1)
        return a % d;

    x = powermod(a, n / 2, d);
    x = x * x % d;
    if (n % 2 == 0)
        return x;
    else
        return x * a % d;
}
