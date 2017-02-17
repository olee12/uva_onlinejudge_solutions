#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n<2 || m < 2 || n < m)
        {
            puts("Boring!");
            continue;
        }
        vector<int> res;
        res.push_back(n);
        bool flag = false;
        while(n!=1)
        {
            if(n%m != 0)
            {
                flag = true;
                break;
            }
            else
            {
                res.push_back(n/m);
                n/=m;

            }
        }
        if(flag)             puts("Boring!");
        else
        {
            for(int i = 0; i<(int)res.size(); i++)
            {
                if(i) printf(" ");
                printf("%d",res[i]);
            }
            puts("");
        }

    }
    return 0;
}
