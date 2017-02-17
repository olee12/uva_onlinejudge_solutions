#include<stdio.h>
int main()
{
    long int n,a,b;
    while(scanf("%d",&n)==1){
        while(n--){
            scanf("%ld %ld",&a,&b);
        if((b>a)||((a-b)%2)!=0) printf("impossible\n");
        else
            printf("%ld %ld\n",(a-b)/2 + b,(a-b)/2);
    }
    }
    return 0;
}
