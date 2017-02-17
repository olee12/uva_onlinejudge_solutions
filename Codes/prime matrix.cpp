#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
#define MAX 100500

bool flag[MAX];
int prime[MAX];
int c=1;
int hi;
int lo;
int matrix[505][505];
void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    flag[3]=0;
    prime[c++]=2;
    register int i,j,add;
    for(i = 4; i<MAX; i+=2) flag[i]=1;
    for(i = 3; i<MAX; i+=2)
    {
        if(flag[i]==0)
        {
            prime[c++]=i;
            if(MAX/i>=i)
            {
                add=i*2;
                for(j = i*i; j<MAX; j+=add ) flag[j]=1;
            }
        }
    }
}
void bins(int n)
{
    lo = 1;
    hi = c-1;
    int mid;
    while(lo<hi)
    {
        mid = (hi+lo)/2;
        if(n>prime[mid]) lo=mid+1;
        else hi = mid;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    sieve();
    /* for(int i = 1;i<100;i++){
         printf("%d %d\n",i,flag[i]);
     }*/
    int row,col,i,j,k,cost,min_cost;
    while(cin>>row>>col)
    {

        for(i = 0; i<row; i++)
        {
            for(j = 0; j<col; j++)
            {
                cin>>matrix[i][j];

            }

        }
        min_cost = 1e6;
        for(i = 0; i<row; i++)
        {
            cost = 0;
            for(j = 0; j<col; j++)
            {
                int x = matrix[i][j];

                if(flag[x])
                {
                    bins(x);
                    cost += (prime[lo]-x);

                }


            }

            if(min_cost>cost) min_cost = cost;
        }
        for(i = 0; i<col; i++)
        {
            cost = 0;
            for(j = 0; j<row; j++)
            {
                int x = matrix[j][i];
                if(flag[x])
                {
                    bins(x);
                    cost +=(prime[lo]-x);
                }

            }
            if(min_cost>cost) min_cost = cost;
        }
        printf("%d\n",min_cost);
    }
    return 0;


}
/*
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
#define MAX 100500

bool flag[MAX];
int prime[MAX];
int c=1;
int hi;
int lo;
int matrix[505][505];
void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    flag[3]=0;
    prime[c++]=2;
    register int i,j,add;
    for(i = 4; i<MAX; i+=2) flag[i]=1;
    for(i = 3; i<MAX; i+=2)
    {
        if(flag[i]==0)
        {
            prime[c++]=i;
            if(MAX/i>=i)
            {
                add=i*2;
                for(j = i*i; j<MAX; j+=add ) flag[j]=1;
            }
        }
    }
}
void bins(int n)
{
    lo = 1;
    hi = c-1;
    int mid;
    while(lo<hi)
    {
        mid = (hi+lo)/2;
        if(n>prime[mid]) lo=mid+1;
        else hi = mid;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    sieve();

    int row,col,i,j,k,cost,min_cost;
    while(cin>>row>>col)
    {

        for(i = 0; i<row; i++)
        {
            for(j = 0; j<col; j++)
            {
                cin>>matrix[i][j];

            }

        }
        min_cost = 1e6;
        for(i = 0; i<row; i++)
        {
            cost = 0;
            for(j = 0; j<col; j++)
            {
                int x = matrix[i][j];

                if(flag[x])
                {
                    int *it = lower_bound(prime,prime+c,x);
                    cost += (*it-x);

                }


            }

            if(min_cost>cost) min_cost = cost;
        }
        for(i = 0; i<col; i++)
        {
            cost = 0;
            for(j = 0; j<row; j++)
            {
                int x = matrix[j][i];
                if(flag[x])
                {
                    int *it = lower_bound(prime,prime+c,x);
                    cost +=(*it-x);
                }

            }
            if(min_cost>cost) min_cost = cost;
        }
        printf("%d\n",min_cost);
    }
    return 0;


}
*/
