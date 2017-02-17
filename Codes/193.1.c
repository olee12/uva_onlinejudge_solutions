#include<stdio.h>
#include<string.h>
int main()
{
    char str[90];
    gets(str);
    mystrcat(str,"world.");
    printf(str);
}

void mystrcat(char *to,char *from)
{
    to=to+strlen(to)-1;
    while(*from) *to++ = *from++;
    *to='\0';
}
