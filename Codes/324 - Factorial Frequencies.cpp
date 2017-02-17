#include<stdio.h>
#include<string.h>

char f[10000];
char factorial[1010][10000];
void multiply(int k);
void fac();
void disply(int n);
int main()
{
    int n;
    factorial[0][0]='1';
    factorial[1][0]='1';
    fac();
    while(scanf("%d",&n)==1 && n) disply(n);
    return 0;


}

void fac()
{
    int k;
    strcpy(f,"1");
    for(k=2; k<370; k++)
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
        for(j=0; j<i; j++)
            factorial[k][j] = f[j];
        factorial[k][i]='\0';
    }
}
void disply(int n)
{
    int i;
    int total[10]={0};
    printf("%d! --\n",n);
    int len = strlen(factorial[n]);
    for(i=len-1; i>=0; i--){
       total[(factorial[n][i]-'0')]++;
    }
        printf(" (0)%5d (1)%5d (2)%5d (3)%5d (4)%5d\n (5)%5d (6)%5d (7)%5d (8)%5d (9)%5d\n",total[0],total[1],total[2],total[3],total[4],total[5],total[6],total[7],total[8],total[9]);

}

