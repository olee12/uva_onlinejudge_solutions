#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    int x1,x2,x3,x4;
    int num;
    int res;
    while(scanf("%d",&num)==1){
        x1=num & 0xff000000;
        x2=num & 0x00ff0000;
        x3=num & 0x0000ff00;
        x4=num & 0x000000ff;
        x1>>=24;
        x2>>=8;
        x3<<=8;
        x4<<=24;
        x4&=0xff000000;
        x3&=0x00ff0000;
        x2&=0x0000ff00;
        x1&=0x000000ff;
        res=x1+x2+x3+x4;
        printf("%d converts to %d\n",num,res);

    }
    return 0;

}
