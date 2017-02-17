/*#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int n=0,d,i,j,k,l;
    while(scanf("%s",str)==1){
            if(str[0]=='0'&&str[1]=='\0') break;
        l=strlen(str);
        d = str[l-1] - '0';
        printf("%d\n",n);
        for(i=0;i<l-1;i++) n+=(str[i]-'0');
        n-=(5*d);
        printf("%d\n",n);
        if(n<0) n*=(-1);
        if(n%17) printf("0\n");
        else printf("1\n");
        n=0;
    }
    return 0;
}*/

/*#include<stdio.h>
#include<string.h>
int main()
{
    int i,sum,rem,l;
    char s[1000];
    while(gets(s))
    {
        rem=0;
        l=strlen(s);
        if(l==1 && s[0]=='0')
            break;
        for(i=0; i<l; i++)
        {
            sum=rem*10+(s[i]-'0');
            printf("sum=%d\n",sum);
            rem=sum%17;
            printf("rem = %d\n",rem);
        }
        if(rem==0)
            printf("1\n");
        else
            printf("0\n");
    }
}*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int sum,rem,i,l;
    while(gets(str)){
        rem=0;
        l=strlen(str);
        if(str[0]=='0'&&str[1]=='\0') break;
        for (i=0;i<l ;i++ ){
            sum = (rem*10)+(str[i]-'0');
            rem=sum%17;
        }
        if(rem) printf("0\n");
        else printf("1\n");
            ;

    }
    return 0;
}
