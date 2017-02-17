#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAN(x) (x)>0 ? (x) : -(x)
int main()
{
    int h,m;
    double a;
    while(scanf("%d:%d",&h,&m)==2&&(h||m)){
        a=MAN(60.0*h-11.0*m);
        if(a>360){
            a=720-a;
        }
        printf("%.3lf\n",a*0.5f);
    }
}
