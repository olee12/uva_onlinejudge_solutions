#include<stdio.h>
#include<string.h>
int  main()
{
    char s[80],*str;
    gets(s);
    str = s;
    int space;
    for(space = 0; *str; str++)
    {
        if(*str != ' ') continue;
        space++;
    }
    printf("%d spaces.\n",space);
    return 0;
}
