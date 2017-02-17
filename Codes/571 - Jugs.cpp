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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;

void RD(int &x)
{
    scanf("%d",&x);
}
void RD(ll &x)
{
    scanf("%I64d",&x);
}
void RD(double &x)
{
    scanf("%lf",&x);
}
void RD(int &x,int &y)
{
    scanf("d",&x,&y);
}
void RD(ll &x,ll &y)
{
    scanf("I64d",&x,&y);
}
void RD(double &x,double &y)
{
    scanf("lf",&x,&y);
}
void RD(char *s)
{
    scanf("%s",s);
}
void RD(char &s)
{
    scanf("%c",&s);
}
void RD(string &s)
{
    cin>>s;
}

void PR(int x)
{
    printf("%d\n",x);
}
void PR(int x,int y)
{
    printf("%d %d\n",x,y);
}
void PR(ll x)
{
    printf("%I64d\n",x);
}
void PR(char x)
{
    printf("%c\n",x);
}
void PR(char *x)
{
    printf("%s\n",x);
}
void PR(string x)
{
    cout<<x<<endl;
}

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define sf scanf
#define pf printf
#define X first
#define Y second

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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
#define INF (1<<30)

#define SZ 10005
struct jug
{
    int a,b;
};
string s[]= {"fill A","fill B","empty A","empty B","pour A B","pour B A","success"};
int dist[SZ][SZ];
int root[SZ][SZ];
jug parent[SZ][SZ];
void display(int a,int b)
{
    if(dist[a][b]!=0)
    {
        display(parent[a][b].a,parent[a][b].b);
        pf("%s\n",s[ root[a][b] ].c_str());
    }
}

int main()
{

    jug inp,u,v;
    int a,b,N;
    int x;
    while(sf("%d %d %d",&inp.a,&inp.b,&N)==3)
    {
        for(int i = 0; i<1002; i++) for(int j = 0; j<10002; j++) dist[i][j]=INF;
        u.a = 0;
        u.b = 0;
        dist[u.a][u.b]=0;
        queue<jug> Q;
        Q.push(u);
        while(Q.empty()==0)
        {

            u = Q.front();
            Q.pop();
            if(u.b==N) break;
            x = dist[u.a][u.b] + 1;
            /// fill A
            v.a = inp.a;
            v.b = u.b;
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=0;
                Q.push(v);

            }
            ///fill B
            v.a = u.a;
            v.b = inp.b;
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=1;
                Q.push(v);

            }
            ///empty A
            v.a = 0;
            v.b = u.b;
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=2;
                Q.push(v);

            }
            ///empty B
            v.a = u.a ;
            v.b = 0;
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=3;
                Q.push(v);

            }
            /// pour A B
            if((u.a + u.b) >= inp.b)
            {
                v.a = u.a - (inp.b - u.b);
                v.b = inp.b;
            }
            else
            {
                v.b = u.a+u.b;
                v.a = 0;
            }
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=4;
                Q.push(v);

            }

            /// pour B A
            if((u.a + u.b) >= inp.a)
            {
                v.b = u.b - (inp.a - u.a);
                v.a = inp.a;
            }
            else
            {
                v.a = u.a+u.b;
                v.b = 0;
            }
            if(dist[v.a][v.b] > x)
            {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                root[v.a][v.b]=5;
                Q.push(v);

            }

        }
        //  puts("fawff");
        display(u.a,u.b);
        puts("success");
    }
    return 0;

}
