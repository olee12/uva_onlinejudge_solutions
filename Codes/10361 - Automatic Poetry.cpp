/*
 * 10361 - Automatic Poetry.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: Olee
 */

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int, int> mii;
typedef long long ll;

#define clr(a) (a.clear())

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 2000050
#define sf scanf
#define pf printf
#define INF 2147483645

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

int main(int argc, char **argv)
{
    char inp1[105];
    char inp2[105];
    string s2, s3, s4, s5;
    int n;
    sf("%d", &n);
    int f;
    getchar();
    while (n--)
    {
        s2 =""; s3 =""; s4 =""; s5 = "";
        f = 1;
        gets(inp1);
        gets(inp2);
        for (int i = 0; inp1[i]; i++)
        {
           // ein kind haelt seinen <schn>abel <n>ur
//wenn es haengt an der ...
            char &ch = inp1[i];
            if (inp1[i] != '<' && inp1[i] != '>')
            {
                pf("%c", inp1[i]);
                if (f == 2)
                {
                    s2 += inp1[i];
                }
                if (f == 3)
                {
                    s3 += inp1[i];
                }
                if (f == 4)
                {
                    s4 += inp1[i];
                }
                if (f == 5)
                {
                    s5 += inp1[i];
                }

            }
            else if(ch=='<' && f==1) f=2;
            else if(ch=='>' && f == 2) f = 3;
            else if(ch=='<' && f==3) f = 4;
            else if(ch=='>' && f == 4) f = 5;

            }

        puts("");
       // cout<<"s2 : "<<s5;//<<"s3 : "<<s3<< "s4 : "<<s4<<"s5 : "<<s5<<endl;
        for (int i = 0; inp2[i]; i++)
        {
            if (inp2[i] == '.' && inp2[i + 1] == '.' && inp2[i + 2] == '.')
                break;
            else
                pf("%c", inp2[i]);
        }
        cout << s4 << s3 << s2 << s5 << "\n";

    }
    return 0;
}

