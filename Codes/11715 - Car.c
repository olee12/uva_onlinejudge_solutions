#include<stdio.h>
#include<math.h>
int main()
{
    int t,i=1;
    register double a,b,c,x,y;
    while(scanf("%d",&t)==1 && t!=0)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        switch(t)
        {
        case 1:
            y=(b-a)/c;
            x=c*a + 0.5*c*c*y;
            break;
        case 2:
            y=(b-a)/a;
            x=a*y + 0.5*y*y*c;
            break;
        case 3:
            x=sqrt(a*a + 2.0*b*c);
            y=(x-a)/b;
            break;
        case 4:
            x=sqrt(a*a - 2.0*b*c);
            y=(a-x)/b;
            break;

        }
        printf("Case %d: %0.3lf %0.3lf\n",i++,x,y);
    }
    return 0;
}
