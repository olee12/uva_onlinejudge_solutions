#include <bits/stdc++.h>

using namespace std;
int ara[50];
int main(int argc, char **argv)
{
    int test;
    int n, val;
    int pw;
    int ans;
    int cnt;
    int tmp;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++)
    {
        cnt = ans = 0;
        scanf("%d %d", &val, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", ara + i);
        pw = (1 << n) - 1;
        while (pw)
        {
            cnt = 0;
            tmp = 1;
            for (int i = 0; i < n; i++)
            {

                if (pw & (1 << i))
                {
                    tmp *= ara[i];
                    cout<<ara[i]<<' ';
                    cnt++;
                }

            }
            puts("");
            printf("val = %d , tmp = %d , cnt = %d , val/tmp = %d\n",val,tmp,cnt,val/tmp);

            tmp = val / tmp;
            if ((cnt & 1) == 0)
                tmp *= -1;
            ans += tmp;
            cout << ans<< endl;
            pw--;
        }
       // cout << val - ans << endl;
        printf("Case %d: %d\n", cas, (val - ans));

    }
    return 0;
}
