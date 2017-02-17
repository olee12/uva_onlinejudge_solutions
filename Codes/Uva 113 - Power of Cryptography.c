#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    while(scanf("%lf %lf",&a,&b)==2)
    {
        c = pow(b,1/a);
        printf("%.0lf\n",c);
    }
    return 0;
}


#include<stdio.h>
#include<math.h>
int main()
{
    double n,p,k;
    while(scanf("%lf %lf",&n,&p)==2)
    {
        k=pow(p,1/n);
        printf("%.0lf\n",k);
    }
    return 0;
}
