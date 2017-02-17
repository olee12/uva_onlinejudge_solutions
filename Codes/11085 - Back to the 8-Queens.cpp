#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
int row[10];
int cnt = 0;
vector<int > v[100];
bool place(int k,int i)
{
    for(int j = 1; j<=k-1; j++)
    {
        if(row[j]==i || (abs(row[j]-i)==abs(j-k))) return false;

    }
    return true;
}
void queen(int k,int n)
{
    for(int i = 1; i<=n; i++)
    {
        if(place(k,i))
        {
            row[k] = i;
            if(k==n)
            {
                for(int j = 1; j<=n; j++)
                {
                    v[cnt].push_back(row[j]);
                }
                cnt++;
            }
            else queen(k+1,n);
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    queen(1,8);
    //cout<<cnt<<endl;


    bool flag=false;
    int cas = 1;
    int ara[9];
    while(scanf("%d",&ara[0])==1)
    {
        for(int i = 1; i<8; i++) scanf("%d",&ara[i]);

        int mn = 1e6;
        int cst;
        for(int i =  0; i<92; i++)
        {

            cst=0;
            for(int j = 0,k = 7; j<8; j++)
            {
                if(v[i][j]!=ara[j]) cst++;
            }
            if(cst<mn) mn = cst;
        }
        printf("Case %d: %d\n",cas++,mn);
    }
    return 0;

}
