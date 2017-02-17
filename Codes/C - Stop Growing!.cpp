#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<stack>
using namespace std;

int main()
{
    int w, ans;
    long long a, b, c, d, e, s, m;
    scanf("%d", &w);
    for (int t = 1; t <= w; ++t)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &m);
        s = a + b + c + d + e;
        if (s >= m)
        {
            ans = 0;
        }
        else
        {
            if (s <= 0)
            {
                ans = -1;
            }
            else
            {
                ans = 0;
                while (s < m)
                {
                    ++ans;
                    s *= 1;
                }
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
