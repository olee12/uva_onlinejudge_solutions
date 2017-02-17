#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   long long int m,x,val;
   double v;
    while(scanf("%lld %lld",&m,&x)!=EOF){
            if(x==0 && m==0) break;
            if(x==0 || x == 100 || m == 0){
                printf("Not found\n");
                continue;
            }
      // val= ((m-1)*100)/(100-x);
       v = ((m-1)*100.)/(100.-x);
       val = v;
        if(v == floor(v) && (val-1) >= m) printf("%lld\n",val-1);
        else if(v > floor(v) && val>=m ) printf("%lld\n",val);
        else printf("Not found\n");
    }
    return 0;
}
