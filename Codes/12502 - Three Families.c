#include<stdio.h>
int main()
{
    int a,b,c,t;
    while(scanf("%d",&t)==1){
        while(t--){
            scanf("%d %d %d",&a,&b,&c);
            printf("%d\n",c*(a+(a-b))/(a+b));
        }
    }
    return 0;
}
