#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,i,j;
    while(scanf("%d %d",&a,&b)==2){
        if(a==-1 && b==-1) break;
        if(a>b) a^=b^=a^=b;
        if(((100-b)+a)<(b-a)) printf("%d\n",(100-b)+a);
        else printf("%d\n",b-a);
    }
    return 0;
}
