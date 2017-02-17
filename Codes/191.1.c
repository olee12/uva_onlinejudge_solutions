#include<stdio.h>
void myputs(char *p);
int main()
{
    myputs("This is a test.");
}

void myputs(char *p)
{
    while(*p) printf("%c",*p++);
    printf("\n");

}
