#include<stdio.h>

int main()
{
    char s[100000],*p;
    long int i,j=0;

    while(gets(s)){

        p=s;
        while(*p){
            if(*p=='"'){

            if(!j) printf("``"),j=1,p++;

            else printf("''"),j=0,p++;
            }

            else printf("%c",*p++);

        }
        printf("\n");
    }
    return 0;
}
