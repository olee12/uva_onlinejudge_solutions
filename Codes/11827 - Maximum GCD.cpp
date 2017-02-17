#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<sstream>
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("input.txt","r",stdin);
    string str;
    int test;
    ll ara[110];
    cin>>test;
    getline(cin,str);
    ll a;
    ll c;
    int cnt;
    while(test--)
    {
        cnt = 0;
        getline(cin,str);
        istringstream ss(str);
        while(ss>>ara[cnt]) cnt++;
       ll mx = 1;
        for(int i = 0; i<cnt; i++)
            for(int j = i+1; j<cnt; j++)
            {
                mx  = max(mx,__gcd(ara[i],ara[j]));

            }
        printf("%lld\n",mx);
       // getchar();
    }
    return 0;
}
