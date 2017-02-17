#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int min;
    while(scanf("%d",&min)==1){
        if(min%6) printf("N\n");
        else printf("Y\n");

    }
    return 0;
}
