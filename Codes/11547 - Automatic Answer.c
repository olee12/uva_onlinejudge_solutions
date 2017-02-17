#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        b = (((b*63) +7492) * 5)-498;
        if(b<0)
            b *=-1;
        printf("%d\n",(b/10)%10);
    }
    return 0;
}
