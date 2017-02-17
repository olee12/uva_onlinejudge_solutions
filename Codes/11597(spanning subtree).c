#include<stdio.h>
int main()
{
    int a,b,i=1;
    while(scanf("%d",&a)==1){
            if(a==0) break;
     printf("Case %d: %d\n",i++,a/2);
    }
    return 0;
}
