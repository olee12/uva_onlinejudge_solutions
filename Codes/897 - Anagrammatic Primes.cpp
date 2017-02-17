#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iterator>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<cstdlib>
using namespace std;
/*#define M 10000005
bool flag[M];
int c;
int prime[664585];
void sieve()
{
    int add;
    int sq = (int) sqrt(M);
    prime[c++]=2;
    for(int i = 4; i<M; i+=2) flag[i]=true;
    for(int i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(sq >=i)
            {
                int add = i*2;
                for(int j = i*i; j<M; j+=add) flag[j]=true;
            }
        }
    }
*/
/*sieve();
char str[100];
cout<<c<<endl;
int a = 0;

for(int i = 4; i<c; i++)
{
    sprintf(str,"%d",prime[i]);
    sort(str,str+strlen(str));
    bool f=true;
    x++;
    do
    {

        if(flag[atoi(str)]!=0)
        {
            f=false;
            break;
        }

    }
    while(next_permutation(str,str+strlen(str)));
    if(f) cout<<prime[i]<<endl;
    // cout<<prime[i]<<endl;
}
cout<<a<<endl;
cout<<x<<endl;*/
//}
#include<iostream>
int ara[]= {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
int main()
{

    int x=0;
    bool f;
    while(scanf("%d",&x),x)
    {
        f=true;
        if(x>=991) puts("0");
        else
        {
            if(x<10)
            {
                for(int i = 0; ara[i]<10; i++)
                {
                    if(ara[i]>x)
                    {
                        f = false;
                        printf("%d\n",ara[i]);
                        break;
                    }


                }
                if(f) puts("0");
            }

            else if(x<100)
            {
                for(int i = 0; ara[i]<=100; i++)
                    if( ara[i]>x)
                    {
                        f=false;
                        printf("%d\n",ara[i]);
                        break;
                    }
                if(f)
                    printf("0\n");
            }
            else
            {
                for(int i = 0; ara[i]<=991; i++)
                    if(ara[i]>x)
                    {
                        printf("%d\n",ara[i]);
                        break;
                    }
            }
        }
    }
    return 0;

}
