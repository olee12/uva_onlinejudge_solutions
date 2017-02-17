#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define M 20010
#define VII vi :: iterator
#define SII si :: iterator
#define MISI map<int,si> :: iterator
#define sc second
map<int,set<int> > tree;
int par[110];
int find_par(int r)
{
    return par[r]==r? r : (par[r]=find_par(par[r]));
}
int main()
{
    // freopen("input.txt","r",stdin);
    bool f = false;
    int test;
    char ara[20];
    int p,t;
    scanf("%d",&test);
    int a,b;
    while(test--)
    {
        scanf("%d %d",&p,&t);
        getchar();
        for(int i = 1;i<=p;i++) par[i]=i;
        if(f) puts("");
        f = true;
        while(gets(ara) && ara[0]!='\0')
        {
            sscanf(ara,"%d %d",&a,&b);
            tree[a].insert(b);
        }
        int cnt = 0;

        for(int i = 1;i<=p;i++){
            for(int j = i+1;j <= p;j++)
            {
                if(tree[i]==tree[j]){
                    int u  = find_par(i);
                    int v  = find_par(j);
                    if(u!=v) par[u]=v;
                }
            }
        }
        for(int i = 1;i<=p;i++) if(i==find_par(i)) cnt++;
        printf("%d\n",cnt);
        tree.clear();
    }
    return 0;
}
