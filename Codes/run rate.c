#include<stdio.h>
int main()
{
    double a,b,c;
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%lf %lf %lf",&a,&b,&c);
            printf("%.02lf %.02lf\n",(b/((300-c)/6.0)),((a+1-b)/(c/6.0)));
        }
    }
    return 0;
}
