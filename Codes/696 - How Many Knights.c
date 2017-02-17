#include<stdio.h>
#include<math.h>
int main()
{
    int temp;
    int a,b,c,i,j;
    while(1)

    {
        scanf("%d %d",&a,&b);
        if(!a&&!b) break;
        if(a==1||b==1) printf("%d knights may be placed on a %d row %d column board.\n",a*b,a,b);
        else if(a==2 || b==2)
        {
            temp=ceil((a*b)/8.0)*4;
            if(a>3)
            {
                if(a%4==1)
                {
                    temp-=2;
                }
            }
            if(b>3)
            {
                if(b%4==1)
                {
                    temp-=2;
                }
            }
            printf("%d knights may be placed on a %d row %d column board.\n",temp,a,b);
        }

        else printf("%d knights may be placed on a %d row %d column board.\n",(a*b+1)/2,a,b);
    }

    return 0;
}
