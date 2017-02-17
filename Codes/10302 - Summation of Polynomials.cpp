
#include<stdio.h>

int main()
{
     long double sum,val;
    while(scanf("%Lf",&val)==1){

            sum=(val*(val+1))/2.0;
    sum*=sum;
        printf("%.0Lf\n",sum);
    }
    return 0;
}
