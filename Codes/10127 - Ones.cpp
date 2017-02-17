#include<cstdio>
using namespace std;
int main()
{
    int num;
    int test;
    int one;
    int n;
    int cnt ;
    while(scanf("%d",&num)==1&&num)
    {
        one = 1;
        cnt = 0;
        n = 1;
        while(n != 0) n = one % num,one = n*10+1,cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
