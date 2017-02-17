#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
template <class T> T egcd(T p,T q,T &x, T &y)
{
    T x1,y1;
    T g;
    if(q==0){
        x=1;
        y=0;
        return p;
    }
    g = egcd(q,p%q,x1,y1);
    x = y1;
    y = (x1-floor(p/q)*y1);
    return g;
}
int main()
{
    int p=17,q=17,x,y;
    int gcd;
    while(scanf("%d %d",&p,&q)!=EOF){
        gcd=egcd(p,q,x,y);
        printf("%d %d %d\n",x,y,gcd);
    }
    return 0;
}
