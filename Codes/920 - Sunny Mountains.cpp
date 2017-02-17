#include<cstring>
#include<cstdio>
#include<iterator>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const double error = 1e-6;
struct point
{
    double x,y;
    bool peek;
    bool operator < (const point& p) const
    {
        return x<p.x;
    }

};
bool is_gret(double x, double y)
{
    return x > y+error; ///x>y
}
bool is_grt_eql(double x, double y)
{
    return x >y-error;
}
point ara[105];
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i = 0;i<n;i++) {scanf("%lf %lf",&ara[i].x,&ara[i].y);ara[i].peek=false;
        }
        double ans = 0;
        sort(ara,ara+n);
        int i = 0;
        if(ara[0].y < ara[1].y) i = 1;
        for(;i<n;i+=2) ara[i].peek = true;
        for(int i = 0;i<n;i++)
        {
            if(ara[i].peek==true)
            {
                double high=0.0;
                for(int j = i+2;j<n;j++)
                {
                    if(is_gret(ara[j].y,high)) high = ara[j].y;
                }
                if(is_grt_eql(high,ara[i].y)) continue;
                point t;
                t.y = high;
                t.x = ara[i].x + ((ara[i].x - ara[i+1].x)*(high - ara[i].y))/(ara[i].y - ara[i+1].y);
                ans += sqrt((t.x-ara[i].x)*(t.x-ara[i].x)+(t.y-ara[i].y)*(t.y-ara[i].y));
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
