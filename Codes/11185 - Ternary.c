#include<stdio.h>
void ter(long long int a);
int main()
{
    long long int a;
    while(scanf("%lld",&a)==1)
    {
        if(a<0) break;
        else if(a==0)
            printf("0");
        ter(a);
        printf("\n");
    }
    return 0;

}
void ter(long long int a)
{
    if(a==0)
        return;
    ter(a/3);
    printf("%lld",a%3);
    return ;
}
