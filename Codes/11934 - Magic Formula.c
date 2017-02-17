#include<stdio.h>
int main()
{
    int a,b,i,c,d,l,x=0;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l)==5 ){
            if(!(a||b||c||d||l)) break;
        for(i=0;i<=l;i++) if(!(((a*i*i)+(b*i)+c)%d)) ++x;

       printf("%d\n",x);
        x=0;
    }
    return 0;
}
