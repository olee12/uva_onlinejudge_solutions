#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define LL long long int
#define LLR unsigned long long int
#define SC(a) scanf("%d",&a)
#define SCR(a) scanf("%lld",&a)
#define SCD(a,b) scanf("%d%d",&a,&b)
#define PF(t) printf("Case %d: ",t)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define PB(a) push_back(a)
#define SET(a) memset(a,0,sizeof a)
#define SETR(a) memset(a,-1,sizeof a)
#define SZ(a) ((int)a.size())
#define P(a) printf("%d\n",a)
#define PL(a) printf("%lld\n",a)
using namespace std;
#define M 99999999
#define eps 1e-9
////
////
//START FROM HERE MAHBUB//
//using namespace std;//
struct data
{
    int x,y,z;
    data() {}
    data(int _x,int _y,int _z)
    {
        x=_x,y=_y,z=_z;
    }
    bool operator<(const data& p)const
    {
        return x<p.x;
    }
};
data ar[1001];
int k;
int as;
int DP[1001][1001];
int pr[1001][1001];
int dp(int i,int j)
{
    if(i==k+1)return 0;
    int &ret=DP[i][j];
    if(ret!=-1)return ret;
    int sum=0,su=0,s;
    if(ar[i].x>ar[j].x&&ar[i].y<ar[j].y)
    {
        su=1+dp(i+1,i);
    }
    s=dp(i+1,j);
    sum=max(s,su);
    if(sum==su)pr[i][j]=1;
    else pr[i][j]=2;
    return ret=sum;
}
int h=0;
void print(int i,int j)
{
    if(i==k+1)return;

    if(pr[i][j]==1)
    {
        cout<<ar[i].z<<endl;
        h++;
        if(h==as)return ;
        print(i+1,i);
    }
    else print(i+1,j);
}
int main()
{
    k=1;
    SETR(DP);
    SETR(pr);
    while(cin>>ar[k].x>>ar[k].y)
    {
        ar[k].z=k;
        k++;
    }
    k--;

    sort(ar+1,ar+k+1);

    ar[0].x=0;
    ar[0].y=10001;
    as=dp(1,0);
    cout<<as<<endl;
    print(1,0);

    return 0;
}
