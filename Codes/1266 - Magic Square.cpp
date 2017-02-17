#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 100000250
#define sf scanf
#define pf printf
#define INF 2147483645
int square[16][16];
void magic(int n)
{
    for(int i = 0; i<n; i++)
        fill(square[i],square[i]+n,0);
    square[0][(n-1)/2]=1;
    int key = 2;
    int i,j,k,l;
    i = 0;
    j = (n-1)/2;
    int zz=n*n;
    while(key<=zz)
    {
        if(i-1 < 0) k = n-1;
        else k = i-1;
        if(j+1 >=n) l = 0;
        else l = j+1;
        if(square[k][l]) i = (i+1)%n;
        else
        {
            i = k;
            j = l;
        }
        square[i][j]=key;
        key++;
    }
    int sum=0;
    zz = ceil(log10(n*n)) + 1;
    for(int i = 0; i<n; i++) sum+=square[0][i];
    pf("n=%d, sum=%d\n",n,sum);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            pf("%*d",zz,square[i][j]);
        puts("");
    }
}
int main()
{
    int n;
    bool f = 0;
    while(sf("%d",&n)==1)
    {
        if(f) puts("");
        f = 1;
        magic(n);

    }
    return 0;
}
