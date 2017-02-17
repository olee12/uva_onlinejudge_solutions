#include<iostream>
#include<cstdio>
#include<cmath>
#define PI 3.141592653589793
using namespace std;
int main()
{
    double x1,x2,y1,y2,x3,y3;
    double a,b,c,s,l,r;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        s=(a+b+c)/2;
        l=sqrt(s*(s-a)*(s-b)*(s-c));
        r=(a*b*c)/(4*l);
        printf("%0.2lf\n",2*PI*r);
    }
    return 0;
}
