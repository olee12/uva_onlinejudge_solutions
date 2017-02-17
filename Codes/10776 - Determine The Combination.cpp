#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
char ara[32];
bool taken[32];
int n,r;
vector<char > result;
void comb(int start)
{
    if(result.size()==r)
    {
        for(int j = 0; j<r; j++)
            printf("%c",result[j]);
        puts("");
    }
    for(int i = start; i<n; i++)
    {
        if(taken[i]==false)
        {
            taken[i]=1;
            result.push_back(ara[i]);
            comb(i+1);
            taken[i]=0;
            result.pop_back();
        }
        while(ara[i]==ara[i+1]) i++;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(scanf("%s %d",ara,&r)==2)
    {
       // puts(ara);

        n = strlen(ara);
        sort(ara,ara+n);
        comb(0);
        result.clear();
        memset(taken,0,sizeof taken);
    }
    return 0;
}
