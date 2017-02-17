#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 150

int n;
char str[MAX];
int cir[MAX];

int power_mod(int a, int n, int mod)
{
    if(n == 0) return 1;
    int ans = power_mod(a, n/2, mod);
    ans = ans*ans%mod;
    if(n%2 == 1) ans = ans*a%mod;
    return ans;
}

void init()
{
    cir[0] = 0;
    for(int i = 1; i <= 102; ++i)
        cir[i] = (cir[i-1]+power_mod(i, i, 10));
}

int main()
{
    init();
//    freopen("input.txt", "r", stdin);
    while(scanf("%s", str) != EOF)
    {
        if(str[0] == '0') break;

        int len = strlen(str);
        if(len >= 2) len = len-2;
        else len = 0;
        sscanf(str+len, "%d", &n);
        //printf("%d\n",n);
        printf("%d\n", cir[n] % 10);
    }

    return 0;
}
