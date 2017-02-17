#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int ara[100];
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    while(scanf("%d",&n)&&n)
    {
        int cnt = 0;
        int ncr = 0;
        for(int i = 0;i<n;i++)
            scanf("%d",&ara[i]);
        for(int i = 0;i<n;i++)
        {
            for(int j= i+1;j<n;j++)
            {
                if(__gcd(ara[i],ara[j])==1) cnt++;
                ncr++;
            }
        }
        if(cnt==0) puts("No estimate for this data set.");
        else {
            double pi = sqrt((ncr*6.00)/(double)cnt);
            printf("%.6lf\n",pi);
        }
    }

}
