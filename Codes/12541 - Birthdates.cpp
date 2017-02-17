#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<iterator>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct date
{
    char name[50];
    int dd;
    int mm;
    int yy;
    bool operator < (const date& p) const
    {
        if(yy == p.yy)
        {
            if(mm == p.mm)
            {
                return dd < p.dd;
            }
            else return mm < p.mm;
        }
        else return yy < p.yy;

    }
};
date ara[120];
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    char str[50];
    int dd,mm,yy;
    scanf("%d ",&n);
    for(int i = 0; i<n; i++)
    {
        scanf("%s %d %d %d",ara[i].name,&ara[i].dd,&ara[i].mm,&ara[i].yy);
        //printf("%s %d %d %d\n",ara[i].name,ara[i].dd,ara[i].mm,ara[i].yy);
    }
    stable_sort(ara,ara+n);
    printf("%s\n",ara[n-1].name);
    printf("%s\n",ara[0].name);
    return 0;

}
