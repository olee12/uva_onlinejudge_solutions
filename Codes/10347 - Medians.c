//Use the Formula area = 3/4 sqrt(s*(s-a)*(s-b)*(s-c)) where s= (a+b+c)/2
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,max,s;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3){
        max=0;
        if(max<a) max = a;
        if(max<b) max = b;
        if(max < c) max = c;
        if(a==0||b==0||c==0) printf("-1.000\n");
        else if((a+b+c-max)<=max) printf("-1.000\n");
        else{
            s = (a+b+c)/2.0;
            printf("%.3lf\n",(4.0/3.0)*sqrt(s*(s-a)*(s-b)*(s-c)));
        }
    }
    return 0;
}
