#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define M 1048577
vi v;
int ara[22][M];

int Power(int i,int j)
{
    int val=1;
    for(int k = 1; k<=j; k++)
        val*=i;
    return val;
}
void func()
{
    for(int i = 2; i<21; i++)
    {
        int max_val = (1<<i)-1;
        int x=0;
        for(int j = (1<<(i-1)); j<=max_val; j+=2)
            ara[i][x++]=j;
        for(int j = (1<<(i-1))+1; j<=max_val; j+=2)
            ara[i][x++]=j;
    }
}


int main()
{
    int d,i;
    int test;
    int dumi;
    scanf("%d",&test);
    while(test--)
    {
        int D,I;
        scanf("%d %d",&D,&I);
        int k=1;
        for(int i = 0; i<D-1; i++)
        {
            //cout<<k;
            if(I%2)
            {
                k=k*2;
                I  = (I+1)/2;
            }
            else
            {
                k = k*2+1;
                I=(I)/2;
            }
        }
        printf("%d\n",k);
    }
    scanf("%d",&dumi);
    return 0;

}








