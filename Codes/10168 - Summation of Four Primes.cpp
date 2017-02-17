#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
#define MAX 10000010
#define LIM 10000010
bool flag[MAX];
int c;
inline void cheak(int num);
void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    flag[3]=0;
    int add;
    for(int i = 4; i<MAX; i+=2) flag[i]=1;
    for(int i = 3; i<MAX; i++)
    {
        if(!flag[i])
        {
            if(MAX/i>=i)
            {
                add = i*2;
                for(int j = i*i; j<MAX; j+=add) flag[j]=1;
            }
        }
    }
}
int main()
{
    sieve();
    // cout<<c<<endl;
    // for(int i=0;i<100;i++) cout<<flag[i]<<endl;
    int num;
    while(cin>>num)
    {

        if(num>=8)
        {
            if(num&1) printf("2 3 "),num-=5;
            else printf("2 2 "),num-=4;

            for(int i = 2; num-i >= 2; i++)
            {
                if(!flag[i] && !flag[num-i])
                {
                    printf("%d %d\n",i,num-i);
                    break;

                }
            }
        }
        else printf("Impossible.\n");


    }
    return 0;

}
