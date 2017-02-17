#include<stdio.h>
#include<string.h>
#define min(i,j) i<j?i:j
#define max(i,j) i>j?i:j
int main()
{
    char str[1000010];
    int i,j;
    int flag;
    int a,b,c=1,t,d;
    while(scanf("%s",str)==1)
    {
        if(!strcmp(str,"\n")) break;
        scanf("%d",&t);
        printf("Case %d:\n",c++);
        while(t--)
        {

            scanf("%d %d",&a,&b);
            flag = 0;
            if(a==b)
            {
                printf("Yes\n");
                continue;
            }

            i=min(a,b);
            j=max(a,b);
            for(a=i; a<j; a++)
            {
                if(str[a]==str[a+1])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
