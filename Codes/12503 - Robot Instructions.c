
#include<stdio.h>

#include<ctype.h>
#include<string.h>

int main()
{
    char str[50];
    int test;
    int i;
    int j;
    int k;
    int flag[105];
    int n;
    scanf("%d",&n);

        while(n--)
        {
            scanf("%d",&test);

                k=0;
                getchar();
                for(i=0; i<test; i++)
                {
                    gets(str);

                    if(!strcmp(str,"LEFT"))
                    {
                        flag[i]=1;
                        k-=1;
                    }
                    else if(!strcmp(str,"RIGHT"))
                    {
                        flag[i]=0;
                        k+=1;
                    }
                    else
                    {
                        j=atoi(&str[8]);

                        if(flag[j-1]){ k-=1;
                        flag[i]=1;
                        }
                        else {k+=1;
                        flag[i]=0;
                        }
                    }

                }
                printf("%d\n",k);

        }

    return 0;
}
