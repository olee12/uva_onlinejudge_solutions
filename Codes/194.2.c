#include<stdio.h>
int main()
{
    char *p;
    int i=0;
    char str[80];
    p=str;
    gets(str);
    while(*p){
        if(*p++ == ' ') i++;

    }
    printf("%d",i);

}
