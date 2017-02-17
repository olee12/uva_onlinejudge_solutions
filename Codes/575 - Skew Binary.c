#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    char ara[100];
    int i,j,m=0;
    while(scanf("%s",ara)==1){
        if(ara[0]=='0'&&ara[1]=='\0') break;
        for(j=0;ara[j];j++);
        for(i=0;ara[i];i++,j--){
            m += (ara[i]-'0')*((int)pow(2,j)-1);
        }
        printf("%d\n",m);
        m=0;
    }
    return 0;
}
