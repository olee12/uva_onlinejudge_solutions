#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,k,b;
    char s1[105];
    while(scanf("%d %s",&n,&s1) == 2)
    {
        if(n==0)
            break;
        else
        {
            k = strlen(s1);
            s1[k]='\0';
            b = k/n;

            for(i = 0; i<k; i=i+b)
            {
                for(j=i+b-1; j>=i; j--)
                {
                    if(s1[j]!='\0')
                        printf("%c",s1[j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
