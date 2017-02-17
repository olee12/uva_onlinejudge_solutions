#include<stdio.h>
#include<string.h>
int main()
{
    char s[1005];
    int i,j,k,l,b=0,d;
    while(gets(s))
    {
        l = strlen(s);
        b = 0;
        for(i = 0; i<l; i++)
        {
            if(s[i] == ' ')
            {
                for(d = i -1; d>=b; d--)
                {
                    printf("%c",s[d]);
                }
                b = i+1;
                printf(" ");

            }

        }
        for(i = l-1; i>=b; i--)
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
