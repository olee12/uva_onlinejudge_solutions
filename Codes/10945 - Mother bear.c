#include<stdio.h>
#define TRUE 1
#define FALSE 0

int  main()
{
    while(1)
    {
        int l,lback,tag,flag = TRUE;
        char ara[1000];
        for(l=0; (ara[l]=getchar())!='\n';)
        {
            if((ara[l]!='.')&&(ara[l]!='!')&&(ara[l]!='?')&&(ara[l]!=' ')&&(ara[l]!=','))
                l++;
        }
        ara[l]='\0';
        l=l-1;

        if((ara[0]=='D')&&(ara[1]=='O')&&(ara[2]=='N')&&(ara[3]=='E'))
            break;

        tag = l;
        for(l=0,lback= tag; l<=tag/2; l++,lback--)
        {
            if(ara[l]>='a'&& ara[l]<='z')
                ara[l] ='A' + ara[l] - 'a';
            if(ara[lback]>='a'&& ara[lback]<='z')
                ara[lback]='A' + ara[lback]-'a';
            if(ara[l]!= ara[lback])
            {
                flag=FALSE;
                break;
            }

        }
        if(flag) printf("You won't be eaten!\n");
        else printf("Uh oh..\n");

    }
    return ;

}
