/*#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,l1,l2;
    char s1[25],s[25];
    scanf("%d",&t);

    while(t--)
    {
        scanf("%s",s);
        scanf("%s",s1);
        l1=strlen(s);
        l2=strlen(s1);
        if(l1==l2)
        {
            for(i=0; i<l1; i++)
            {
                if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'))
                {
                    if(s[i]!=s1[i])
                    {
                        j=0;
                        break;
                    }
                }
                else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
                    {
                        j=1;
                        continue;
                    }
                    else
                    {
                        j=0;
                        break;
                    }

                }
            }
        }
        else j=0;
        if(j) printf("Yes\n");
        else printf("No\n");
    }

    return 0;

}*/
#include<stdio.h>
#include<string.h>
int cheak(register char ch,register char *s);
int main()
{
    register i,j,l;
    int t;
    char s[25],s1[25];
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s %s",s,s1);
        for(i=0; s[i]; i++);
        for(j=0; s1[j]; j++);
        if(i^j)
        {
            printf("No\n");
            continue;
        }
        else
        {
            l=1;
            for(i=0; s[i]; i++)
            {
                if(s[i]^s1[i])
                    if(!cheak(s[i],"aeiou")|| !cheak(s1[i],"aeiou"))
                    {
                        l=0;
                        break;
                    }
            }
        }
        if(l) printf("Yes\n");
        else printf("No\n");


    }
    return 0;

}
int cheak(register char ch,register char s[])
{
    register int i;
    for(i=0; s[i]; i++)
        if(s[i]==ch)
            return 1;
    return 0;
}
