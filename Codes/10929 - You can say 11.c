#include<stdio.h>
#include<string.h>
int main()
{
    char num[1010];
    int a=0,i,j,b=0;
    while(scanf("%s",num)==1){
            a = b = 0;
        j = strlen(num);
        num[j] = '\0';
        if(num[0] == '0'&&num[1]=='\0')
            break;

        for (i=0; i<j; i++ ){

            if((i%2)==0){
                a += num[i] - 48;
            }
            else
                b += num[i] - 48;
        }
        b = b*-1;
        if(((a+b)%11)==0)
            printf("%s is a multiple of 11.\n",num);
        else
            printf("%s is not a multiple of 11.\n",num);

        }
    return 0;
}
