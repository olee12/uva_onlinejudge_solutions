#include<stdio.h>
int main()
{
    int r,n;
    int j=1,s;
    while(scanf("%d %d",&r,&n)==2 && (r+n))
    {
        if(r/n==0)
        {
            printf("Case %d: 0\n",j++);
            continue;
        }
        else if(((r-n) / n) > 26)
        {
            printf("Case %d: impossible\n",j++);
            continue;
        }
        else if((r-n)%n==0)
            s=(r-n)/n;
        else if((r-n)%n!=0)
            s = (r-n)/n + 1;

        printf("Case %d: %d\n",j++,s);

    }
    return 0;
}


/*#include<stdio.h>
#include<math.h>
int main()
{
    int r,n,s,k=1;


    while(scanf("%d%d",&r,&n)==2 && (r+n))
    {
        if(r/n==0)
        {
            printf("Case %d: 0\n",k++);
            continue;
        }
        s=ceil((double)(r)/n)-1;
        if(s>26)
            printf("Case %d: impossible\n",k++);
        else
            printf("Case %d: %d\n",k++,s);
    }
    return 0;
}*/
