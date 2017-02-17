#include<stdio.h>

int main()
{
    int a;
    register int b=0,i=0;
    int ara[33];
    while(scanf("%d",&a)==1 && a){
        while(a!=0){
            ara[i++]=a%2;
            if(a%2) b++;
            a/=2;
        }
        --i;
        printf("The parity of ");
        for(;i>=0;i--){
            printf("%d",ara[i]);
        }
        printf(" is %d (mod 2).\n",b);
        b=0,i=0;
    }
    return 0;

}

