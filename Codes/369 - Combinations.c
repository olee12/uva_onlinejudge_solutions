#include<stdio.h>
double factorial(double n);
double conbination(double n,double r);
int main()
{
    double n,r;
    while(scanf("%lf %lf",&n,&r)==2 && n && r){
        printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",n,r,conbination(n,r));
    }
    return 0;
}
double conbination(double n,double r)
{
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}
double factorial(double n)
{
    if(n<=1) return 1.0;
    return (n*factorial(n-1));
}
