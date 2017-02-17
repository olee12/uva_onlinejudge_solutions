#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c;
    double r,s;
    while(cin>>a>>b>>c){
        if(a==0||b==0||c==0)
            printf("The radius of the round table is: 0.000\n");
        else {
            s=(a+b+c)/2;
            r=sqrt(s*(s-a)*(s-b)*(s-c))/s;
            printf("The radius of the round table is: %.3lf\n",r);
        }
    }
    return 0;
}
