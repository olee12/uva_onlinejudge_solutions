#include<stdio.h>

int main()
{
    int a=1,b=1,c=1,d=1,e=1,f=1;
    char s[30];
    int i;
    while(scanf("%s",s)==1){

        for (i=0;s[i] ;i++ ){
            if(a && (s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V'))
                printf("%d",1),a=0,b=1,c=1,d=1,e=1,f=1;
            else if(b && ((s[i]=='C'||s[i]=='G' || s[i]=='J' || s[i]=='K' || s[i]=='Q' || s[i]=='S' || s[i]=='X' || s[i]=='Z')))
                printf("%d",2),a=1,b=0,c=1,d=1,e=1,f=1;
            else if(c && (s[i]=='D'||s[i]=='T'))
                printf("%d",3),a=1,b=1,c=0,d=1,e=1,f=1;
            else if(d && s[i]=='L')
                printf("%d",4),a=1,b=1,c=1,d=0,e=1,f=1;
            else if(e && (s[i]=='M'||s[i]=='N'))
                printf("%d",5),a=1,b=1,c=1,d=1,e=0,f=1;
            else if(f && s[i]=='R')
                printf("%d",6),a=1,b=1,c=1,d=1,e=1,f=0;
            else if((s[i]=='A'||s[i]=='O'||s[i]=='W'||s[i]=='Y'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='H')){
                a=1,b=1,c=1,d=1,e=1,f=1;
            }


        }
        printf("\n");
        a=1,b=1,c=1,d=1,e=1,f=1;
    }
    return 0;
}
