#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
   long double a,s,red,arc,crod,deg;
    string str;
    while(cin>>s>>a>>str){
        if(str=="min"){
            if(a>180) a=360-a;
            deg=a/60.0;
            red=pi*deg/180.00;

        }
        else {
            if(a>180) a=360-a;
            red=a*pi/180.0;
        }
        arc=(s+6440)*red;
        crod=2*(s+6440)*sin(red/2.00);
        printf("%.6Lf %.6Lf\n",arc,crod);
    }
    return 0;
}
