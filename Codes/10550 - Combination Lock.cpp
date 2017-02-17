#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int i,a,b,c;
    int res;
    while(scanf("%d %d %d %d",&i,&a,&b,&c)==4)
    {
        if(i==0 && b==0 && c==0 && a==0) return 0;
        res = 0;
        res+=80;
        if(i-a > 0) res+= (i-a);
        else
        res+=(i+40-a);
        res+=40;
        if(b-a > 0) res+=(b-a);
        else
        res+=(40-a+b);
        if(b-c > 0) res+=(b-c);
        else
        res+=(b+40-c);
        printf("%d\n",res*9);
    }
    return 0;
}
