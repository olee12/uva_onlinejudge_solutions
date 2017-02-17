#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    int y4,y15,y55,y100,y400,i,l,c=0;
    while(scanf("%s",&s)==1){
        y4=0;y15=0;y100=0;y400=0;y55=0;
        if(c > 0)
            printf("\n");
        c++;
        l = strlen(s);
        for(i=0;i<l;i++){
        y4=(y4*10+(s[i]-'0'))%4;
        y15=(y15*10+(s[i]-'0'))%15;
        y100=(y100*10+(s[i]-'0'))%100;
        y55=(y55*10+(s[i]-'0'))%55;
        y400=(y400*10+(s[i]-'0'))%400;
        }
        if((!y4 && y100) || !y400){
            printf("This is leap year.\n");
            if(!y15)
                printf("This is huluculu festival year.\n");
            if(!y55)
                  printf("This is bulukulu festival year.\n");

        }
        else{
            if(!y15)
                  printf("This is huluculu festival year.\n");
            else printf("This is an ordinary year.\n");
        }
    }
    return 0;
}
