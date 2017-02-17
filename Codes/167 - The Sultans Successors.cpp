#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int row[10];
int board[10][10];
int sum;
int mx;
bool place(int k,int i)
{
    for(int j = 1; j<=k-1; j++)
    {
        if(row[j]==i || (abs(row[j]-i) == abs(j - k))) return false;
    }
    return true;
}
void queen(int k,int n)
{
    for(int i = 1; i<=n; i++)
    {
        if(place(k,i))
        {
            row[k]=i;
            if(k == n)
            {
                for(int j = 1; j<=8; j++)
                {
                    sum+= board[j][row[j]];
                }
                if(sum > mx) mx = sum;
                sum = 0;

            }
            else
                queen(k+1,n);
        }
    }

}
int main()
{

    freopen("input.txt","r",stdin);

    int test;
    scanf("%d",&test);
    while(test--)
    {
        for(int i = 1; i<=8; i++)
        {
            for(int j = 1; j<=8; j++)
                scanf("%d",&board[i][j]);
        }
        sum = 0;
        mx  = 0;
        queen(1,8);
        printf("%5d\n",mx);
    }
    return 0;
}
