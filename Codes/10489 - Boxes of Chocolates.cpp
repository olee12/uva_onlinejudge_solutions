#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int f,b;
    int ans;
    int x;
    int m;
    int k;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&f,&b);
        ans = 0;
        while(b--){
        scanf("%d",&k);
        m = 1;
        while(k--)
        {
            scanf("%d",&x);
            m = (m*x)%f;
        }
        ans+=(m%f);
        }
        printf("%d\n",ans%f);
    }
    return 0;
}
