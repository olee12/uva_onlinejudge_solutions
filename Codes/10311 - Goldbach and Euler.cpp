#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100000005
#define L 5761490

char flag[MAX+2];
void sieve()
{
    int sq = sqrt(MAX);
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    register int i,j,add;

    for(i=4; i<=MAX; i+=2) flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {
        if(!flag[i])
        {
            if(sq>=i)
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

  unsigned long long  int num,i,p2;
    while(scanf("%llu",&num)==1)
    {
        if(num%2==1)
        {
            if(num==1) printf("%llu is not the sum of two primes!\n",num);
            else if(flag[num-2]==1) printf("%llu is not the sum of two primes!\n",num);
            else  printf("%llu is the sum of 2 and %llu.\n",num,num-2);
            continue;
        }
        int j;
        int f = 0;
        for(i= num/2,j=0; i< num; i++,j++)
        {

            if(flag[(num/2) - j]==0 && flag[i]==0 && (num/2 - j)!=i)
            {
                printf("%llu is the sum of %llu and %llu.\n",num,(num-i),i);
                f = 1;
                break;
            }
        }
        if(f==0) printf("%llu is not the sum of two primes!\n",num);

    }
    return 0;
}
