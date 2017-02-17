#include<stdio.h>
int main()
{
    int t1,t2,t3,d,e,c1,c2,c3,i,n,a;
    while((scanf("%d",&n))==1)
    {
        for (i=1;i<=n ;i++ ){
            scanf("%d %d %d %d %d %d %d",&t1,&t2,&t3,&a,&c1,&c2,&c3);
            if(c1>=c2&&c3>=c2)
                d = (c1+c3)/2.0;
            else if(c2>=c1&&c3>=c1)
                d = (c2+c3)/2.0;
            else if(c1>=c3&&c2>=c3)
                d = (c1 + c2)/2.0;
            e = t1+t2+t3+a+d;
            if(e>=90)
                printf("Case %d: A\n",i);
            else if(e>=80)
                printf("Case %d: B\n",i);
            else if(e>=70)
                printf("Case %d: C\n",i);
            else if(e>=60)
                printf("Case %d: D\n",i);
            else if(e<60)
                printf("Case %d: F\n",i);
        }


    }
    return 0;
}
