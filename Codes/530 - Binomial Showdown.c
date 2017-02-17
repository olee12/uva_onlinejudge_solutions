/*#include<stdio.h>
double factorial(double n);
double conbination(double n,double r);
int main()
{
    double n,r;
    int c;
    while(scanf("%lf %lf",&n,&r)==2){
        if(n==0&&r==0) break;
        c = conbination(n,r);
        printf("%d\n",c);
    }
    return 0;
}
double conbination(double n,double r)
{
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}
double factorial(double n)
{
    if(n==0) return 1;
    return (n*factorial(n-1));
}
*/
#include<stdio.h>
int main()
{
    int n,r;
    double s=1;
    int i;
    while(scanf("%d %d",&n,&r)==2){
        if(n==0&&r==0) break;
        if(r>n/2) r = n-r;
        for(i=1;i<=r;i++){
            s = s*(n-i+1);
            s/=i;
            printf("%lf\n",s);
        }
        printf("%.0lf\n",s);
        s=1;
    }
    return 0;
}
