#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    unsigned long long int m,x,y;
    while(scanf("%llu",&m ) && m){
        if(m>9){
            y = (m*10)/9;
            x=y-1;
            if(m%9==0) printf("%llu %llu\n",x,y);
            else printf("%llu\n",y);
        }
    }
    return 0;
}
