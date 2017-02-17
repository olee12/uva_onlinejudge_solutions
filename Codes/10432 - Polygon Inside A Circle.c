#include<stdio.h>
#include<math.h>
int main()
{
    double r,s,pi;
    pi = 4*atan(1);
    while(scanf("%lf %lf",&r,&s)==2){
        printf("%.3lf\n",r*r*s*sin((2.00*pi)/s)/2.00);

    }
    return 0;

}
/*#include <stdio.h>
#include <math.h>
int main()
{
    double r,s,PI;
    PI = 4*atan(1);
    while(scanf("%lf %lf",&r,&s)==2)
        printf("%.3lf\n",r*s*r*sin((2.00*PI)/s)/2.00);
    return 0;
}
*/
