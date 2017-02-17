#include<stdio.h>
#include<string.h>

char f[10000];
char factorial[1010][10000];

void fac();

int main()
{
    int n;
    factorial[0][0]='1';
    factorial[1][0]='1';
    fac();
    while(scanf("%d",&n)==1){
             printf("%d!\n",n);
    puts(factorial[n]);


    }
    return 0;


}
void fac()
{
    int k;
    strcpy(f,"1");
    for(k=2; k<1005; k++)
    {
        int cin,sum,i;
        int len = strlen(f);
        cin=0;
        i=0;
        while(i<len)
        {
            sum = cin +(f[i]-'0')*k;
            f[i] = (sum%10) + '0';
            i++;
            cin = sum/10;

        }
        while(cin>0)
        {
            f[i++]=(cin%10)+'0';
            cin/=10;
        }
        f[i] = '\0';
        int j;
        int x;
        factorial[k][i]='\0';
        for(j=i-1,x=0; j>=0;x++, j--)
            factorial[k][x] = f[j];

    }
}
