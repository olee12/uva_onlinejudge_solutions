
/*#include<stdio.h>
#define SZ 1000010
#define SZ2 78510
int reverse(int n);
int c;
int flag[SZ],prime[SZ2];
void sieve(void);
int primech(int a);


int main()
{
    sieve();
    long int n,rev,p,rnp;
    while(scanf("%ld",&n)==1)
    {
        if(n<=1) printf("%ld is prime.\n",n);
        else
        {
            p=primech(n);
            if(p==0) printf("%ld is not prime.\n",n);
            else if(p==1)
            {
                rev=reverse(n);
                rnp=primech(rev);
                if(rnp==1 && n>10 && n!=rev)printf("%ld is emirp.\n",n);
                else printf("%ld is prime.\n",n);
            }
        }
    }
    return 0;
}
int primech(int a)
{
    int i;
    for(i=0; prime[i]<=a; i++)
    {
        if(prime[i]==a) return 1;
    }
    return 0;

}

void sieve(void)
{
    int i,j,add;
    prime[c++]=2;
    for(i=4; i<SZ; i+=2) flag[i] = 1;
    for(i=3; i<SZ; i+=2)
    {
        if(!flag[i])
        {
            prime[c++]=i;
            if(SZ/i>=i)
            {
                add=i*2;
                for(j=i*i; j<SZ; j+=add) flag[j]=1;
            }
        }
    }
}

int reverse(int n)
{
    int a=0,b;
    while(n>0)
    {
        a=(a*10) + (n%10);
        n/=10;

    }
    return a;
}
*/

/*#include <stdio.h>
#include <string.h>
#define N 1000000
_Bool isprime[N+1];
#define true 1
int main()
{
    int i, j;


    for ( i = 2; i*i <= N; i++)
        if (!isprime[i])
            for ( j = 2*i; j <= N; j+=i)
                isprime[j] = true;

    int n;
    int reverse;
    int len;
    char str[7];
    char rev[7];

    while (scanf("%d", &n) != EOF)
    {
        if (isprime[n])
        {
            printf("%d is not prime.\n", n);
            continue;
        }

        snprintf(str, sizeof(str), "%d\0", n);

        len = strlen(str);

        for ( i = len-1, j = 0; i >= 0; i--)
            rev[j++] = str[i];

        rev[j] = '\0';

        sscanf(rev, "%d", &reverse);

        if (!isprime[reverse] && (n != reverse))
            printf("%d is emirp.\n", n);
        else
            printf("%d is prime.\n", n);

    }

    return 0;
}*/
#include<stdio.h>
#include<string.h>
#define N 1000000
_Bool isprime[N+1];
#define true 1
int main()
{
    printf("%d",sizeof(isprime));
    int i,j;
    for(i=2;i*i<=N;i++){
        if(!isprime[i]){

            for(j=i*i;j<=N;j+=i) isprime[j] = true;
        }
    }

    int n,len,reverse;
    char str[7];
    char rev[2];
    while(scanf("%d",&n)!=EOF){
        if (isprime[n])
        {
            printf("%d is not prime.\n", n);
            continue;
        }
        else{
            snprintf(str,sizeof(str),"%d\0",n);
            len=strlen(str);
            for(i=len-1,j=0;i>=0;i--)
                rev[j++]=str[i];
                rev[j]='\0';
            sscanf(rev,"%d",&reverse);
            if(!isprime[reverse] && (n!=reverse))
                printf("%d is emirp.\n", n);
            else
                printf("%d is prime.\n", n);

        }
    }
    return 0;

}
