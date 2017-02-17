#include<stdio.h>
#include<math.h>
int main()
{
    double r;
    int a,b,i,c=0;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0) break;
        for(i=a;i<=b;i++){
            r=sqrt(i);
            if(r==(int)r)
                c++;
        }
        printf("%d\n",c);
        c=0;
    }
    return 0;

}
