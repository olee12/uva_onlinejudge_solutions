#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c,count=0;
    char sine,ans[100];
    while(scanf("%d%c%d=%s",&a,&sine,&b,ans)==4){

        if(sine=='+'){
                c=atoi(ans);
            if(c==(a+b)) count++;

        }
        else if(sine == '-' ){
            c=atoi(ans);
            if(c==(a-b)) count++;
        }

    }
    printf("%d\n",count);
    return 0;
}
