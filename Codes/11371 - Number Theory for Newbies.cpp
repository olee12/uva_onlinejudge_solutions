#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool big(char a,char b)
{
    return a>b;
}
bool small(char a,char b)
{

    return a<b;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char str[20];
    char ara1[20];
    char ara2[20];
    ll a,b;
    sscanf(ara1,"%lld",&a);
    while(scanf("%s",str)==1)
    {
        char *ara1=str;
        char *ara2=str;
        sort(ara1,ara1+strlen(str),big);
        sscanf(ara1,"%lld",&a);
        sort(ara2,ara2+strlen(ara2),small);
        int i = 0;
        while(ara2[i]=='0') i++;
        ara2[0]=ara2[i];
        if(i) ara2[i]='0';

        sscanf(ara2,"%lld",&b);
        ll c = a-b;
        printf("%lld - %lld = %lld = 9 * %lld\n",a,b,c,c/9);
        // cout<<a<<' '<<b<<endl;
    }
    return 0;
}
