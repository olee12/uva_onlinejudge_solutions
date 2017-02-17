#include<stdio.h>
int main()
{
    int m,a,b,c,d,e,f,g;
    int h,i;
    while(1){
        scanf("%d",&m);
        a = m / 1000;

        m = m%1000;
        b = m /500;
        m = m% 500;
        c = m / 100;
        m = m%100;
        d = m / 50;
        m = m %50;
        e = m/20;
        m = m%20;
        f = m / 10;
        m = m % 10;
        g = m /5;
        m = m%5;
        h = m/2;
        m = m%2;
        i = m/1;
        m= m%1;
        printf("%d %d %d %d %d %d %d %d %d \n",a,b,c,d,e,f,g,h,i);
        a=b=c=d=e=f=g=h=i=0;
    }
}
