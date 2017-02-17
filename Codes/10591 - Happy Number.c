#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int a,t;
    register int i,k,c;
    char str[100];
    while(scanf("%d",&t)==1)
    {
        c=1;
        while(t--)
        {
            scanf("%d",&a); k=0;
            snprintf(str,sizeof(str),"%d",a);
            while(k!=1)
            {
                k=0;
                for(i=0; i<strlen(str); i++)
                    k+=(str[i]-'0')*(str[i]-'0');
                snprintf(str,sizeof(str),"%d",k);
                if(k==4) break;
            }
            if(k==1) printf("Case #%d: %d is a Happy number.\n",c++,a);
            else printf("Case #%d: %d is an Unhappy number.\n",c++,a);
        }

    }
    return 0;
}
