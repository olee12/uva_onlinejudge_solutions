#include<stdio.h>
#include<math.h>
int main()
{
    int test;
    int a,b,r;
    double res;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&a,&b,&r);
        res = sqrt(a*a + b*b);
        printf("%.2lf %.2lf\n",r-res,r+res);
    }
    return 0;
}
