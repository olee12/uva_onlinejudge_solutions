#include<stdio.h>
#include<string.h>

char f[10000];
char factorial[10010][7000];
void multiply(int k);
void fac();
void disply(int n);
int main()
{
    int n;
    factorial[0][0]='1';
    factorial[1][0]='1';
    fac();
    while(scanf("%d",&n)==1)
        if(n==0 || n==1) printf("%5d -> 1\n",n);
        else if(n==3) printf("%5d -> 6\n",n);
        else if(n==2) printf("%5d -> 2\n",n);
    else
        disply(n);
    return 0;
}

void fac()
{
    int k;
    strcpy(f,"1");
    for(k=2; k<10005; k++)
    {

        int cin,sum,i;
        int len = strlen(f);
        cin=0;
        i=0;
        while(i<len && i < 3000)
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
        for(j=0; j<i; j++)
            factorial[k][j] = f[j];
        factorial[k][i]='\0';
    }
}
void disply(int n)
{
    int i;

    int len = strlen(factorial[n]);
    for(i=0; i<len-1; i++)
        if(factorial[n][i]!='0'){ printf("%5d -> %c\n",n,factorial[n][i]);
        break;
        }
}
