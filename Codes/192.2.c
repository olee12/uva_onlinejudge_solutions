#include<stdio.h>
void mstrcpy(char *to,char *from);
int main()
{
    char str[80];
    mstrcpy(str,"this is a test.");
    printf(str);

}

void mstrcpy(char *to,char *from)
{
    while(*from) *to++=*from++;
    *to='\0';
}
