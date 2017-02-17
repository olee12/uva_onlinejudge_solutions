#include<stdio.h>
#include<string.h>
int main()
{
    int i=1,j;
    char str[80],*p;

    while(gets(str))
    {
        p=str;
        if(!strcmp(p,"Hajj")) printf("Case %d: Hajj-e-Akbar\n",i++);
        else if(!strcmp(p,"Umrah")) printf("Case %d: Hajj-e-Asghar\n",i++);
        else if(!strcmp(p,"*")) break;

    }
    return 0;

}
