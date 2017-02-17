/*#include<cstdio>
#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<cstdlib>
using namespace std;
#define MAX 10001000
int flag[MAX];
int pri[50];
vector< int > prime;
int c;
void sieve()
{
    prime.push_back(2);

    register int i,j,add;
    for(i=4; i<=MAX; i+=2)  flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {

        if(!flag[i])
        {

            prime.push_back(i);
            if(MAX/i>i)
            {
                add=i<<1;
                for(j=i*i; j<=MAX; j+=add) flag[j]=1;
            }
        }
    }
}

int main()
{
    sieve();

   long long  int num;
   long long  int large,count;
    int i,t;
    int test;
    while(scanf("%lld",&num) && num)
    {
        if(num < 0) num = abs(num);


        count=0;
        test =0;


        t=1;

        long long  int lim=(long long )sqrt(num);

        for(i=0; prime[i]<=lim; i++)
        {
            while(num%prime[i]==0)
            {
                count++;
                test++;
                large=prime[i];
                num/=prime[i];

            }
            if(num==1 && test==count){
                printf("-1\n");t=0;
                break;
            }
            test =0;
        }

        if(t){
        if(num>1 && count) printf("%lld\n",num);
        else if(count) printf("%lld\n",large);
        else printf("-1\n");
        }
    }
    return 0;
}
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<cstdlib>
using namespace std;
#define MAX 10001000
int flag[MAX];
int pri[50];
vector< int > prime;
int c;
void sieve()
{
    prime.push_back(2);
    register int i,j,add;
    for(i=4; i<=MAX; i+=2)  flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {
        if(!flag[i])
        {
            prime.push_back(i);
            if(MAX/i>i)
            {
                add=i<<1;
                for(j=i*i; j<=MAX; j+=add) flag[j]=1;
            }
        }
    }
}

int main()
{
    sieve();

    long long  int num;
    long long  int large,count;
    int i,t;
    int test;
    while(scanf("%lld",&num) && num)
    {
        if(num < 0) num = abs(num);
        test =0;
        long long  int lim=(long long )sqrt(num);
        for(i=0; prime[i]<=lim; i++)
        {
            if(num%prime[i]==0)
            {
                test++;
                while(num%prime[i]==0)
                {
                    num/=prime[i];
                }
                large=prime[i];
            }
        }
        if(test && num !=1) printf("%lld\n",num);


        else  if(test==1||test==0) printf("-1\n");

        else printf("%lld\n",large);

    }
    return 0;
}

