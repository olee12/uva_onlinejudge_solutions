#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<cctype>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<list>
#include<assert.h>
#include<time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<25)
#define mp make_pair
#define fs first
#define sc second
#define __ std::ios_base::sync_with_stdio (false)

template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

const ll MOD = 1000000007ll;
ll ncr[51][51];
ll dp[11][51][51][11];
int vp[11][51][51][11];

int loop=1;

int cnt[11];

ll rec(int pos,int odd,int even,int M)
{
    if(odd<0 || even<0) return 0;
    if(pos==10)
    {
        return (M==0&&odd==0&&even==0);
    }

    ll &ret = dp[pos][odd][even][M];
    int &vet = vp[pos][odd][even][M];
    if(vet==loop) return ret;
    ret=0;
    vet=loop;
    if(cnt[pos]==0)
    {
        ret=rec(pos+1,odd,even,M)%MOD;
    }
    else
    {
        int hodd = odd, heven = even;
        if(pos == 0) hodd--;
        for(int i = 0; i <= cnt[pos]; i++)
        {
            ll tmp = (ncr[hodd][i] * ncr[heven][cnt[pos] - i]) % MOD;
            int nM = (M+(i * pos - (cnt[pos] - i) * pos)) % 11;
            if(nM < 0) nM += 11;
            tmp = (tmp * rec(pos + 1, odd - i, even - (cnt[pos] - i), nM)) % MOD;
            ret = (ret + tmp);
            if(ret >= MOD) ret -= MOD;
        }
    }

    return ret;
}


int main()
{
    for(int i=0;i<51;i++) ncr[i][0]=ncr[i][i]=1;
    for(int i=1;i<51;i++)
    {
        for(int j=1;j<i;j++)
        {
            ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%MOD;
        }
    }
    char arr[105];

    while(SF("%s",arr)==1)
    {
        clrall(cnt,0);
        int n=strlen(arr);
        for(int i=0;i<n;i++)
        {
            cnt[arr[i]-'0']++;
        }
        int odd=(n+1)>>1;
        int even=n-odd;
//        deb("odd : ",odd,"even : ",even);
        PF("%lld\n",rec(0,odd,even,0));
        loop++;
    }
    return 0;
}




















