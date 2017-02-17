#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int mood = 1000;
typedef long long ll;
ll pow_mood(int n, int k)
{
    if (k == 0) return 1;
    ll temp = pow_mood(n, k >> 1);
    temp = temp * temp % mood;
    if (k & 1) temp = temp * n % mood;
    return temp;
}

int main()
{
    int n,k;
    int test;
    double ix,dx;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&k);
      //  ix =(double)k*log10((double)n);
        //dx = ix - floor(ix);
       // dx=100. *pow(10.,ix - floor(ix));
        printf("%03d...%03lld\n",(int)pow(10.0,2.0+modf((double)k*log10(n),&ix)),pow_mood(n,k));
    }
    return 0;
}

