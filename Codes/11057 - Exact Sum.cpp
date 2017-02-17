#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
#define M 10010
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int ara[M];
    int get,n;
    int tmp;
    int a,b;
    while(scanf("%d",&n)==1)
    {
        for(int i = 0; i<n; i++) scanf("%d",&ara[i]);
        scanf("%d",&get);
        tmp = 1e9;
        for(int i = 0; i<n; i++)
            for(int j = i+1; j<n; j++)
            {
                if((ara[i]+ara[j])==get && tmp > abs(ara[i]-ara[j]))
                {
                    a = ara[i];
                    b = ara[j];
                    //cout<<a<<' '<<b<<endl;
                    tmp = abs(ara[i]-ara[j]);
                }
            }
            if(a>b) a^=b^=a^=b;
        printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
    }
    return 0;
}
