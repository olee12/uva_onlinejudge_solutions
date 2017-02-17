#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define pi 3.1415926535897932384626433832795
int main()
{
    double a,b,c;
    double big_cir;
    double sml_cir;
    double s;
    double trangle;
    double max = 0;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3){

        s = (a+b+c)/2.0;
        trangle = sqrt(s*(s-a)*(s-b)*(s-c));
        sml_cir = trangle/s;
        big_cir = (a*b*c)/(4*trangle);
        printf("%.4lf %.4lf %.4lf\n",(pi*big_cir*big_cir)-trangle,trangle - (pi*sml_cir*sml_cir),pi*sml_cir*sml_cir);

    }
    return 0;
}
