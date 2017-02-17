#include<stdio.h>
int main()
{

    long long int i,n,sum;
    while(scanf("%lld",&n)==1){
            sum=0;
        for(i=3;i<=n;i+=2){
            sum = sum + i*2;
        }
        sum++;
        printf("%lld\n",3*sum-6);
        //printf("%lld\n",sum+sum-2+sum-4);

    }
    return 0;
}
