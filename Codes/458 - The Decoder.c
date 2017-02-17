#include<stdio.h>
#include<string.h>
int main()
{
    char c[1000];
    int i;
    while(gets(c)){
        for(i=0;i<strlen(c);i++)
            printf("%c",c[i]-7);
        printf("\n");
    }


}
