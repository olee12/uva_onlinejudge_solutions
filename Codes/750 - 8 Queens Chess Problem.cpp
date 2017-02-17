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
    //freopen("input.txt","r",stdin);
    queen(1,8);
    //cout<<cnt<<endl;
    int test;
    scanf("%d",&test);
    bool flag=false;
    while(test--)
    {
        if(flag==true) puts("");
        flag = true;
        int cas = 1;
        int x,y;
        scanf("%d %d",&x,&y);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for(int i =  0; i<92; i++)
        {
            if(v[i][y-1]==x)
            {
                if(cas < 10) printf(" ");
                printf("%d     ",cas++);
                for(int j = 0; j<8; j++)
                    printf(" %d",v[i][j]);
                // printf("f");
                printf("\n");
            }
        }
        // if(test) puts("");
    }
    return 0;

}
