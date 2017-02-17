#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<sstream>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii>iii;
typedef vector<int> vi;
typedef vector<pair<int,int> >vii;
typedef vector<iii> viii;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define VII vi :: iterator
#define VIII vii :: iterator
#define MAX (1<<31)-5
struct node
{
    int u,w,cst;
    node() {}
    node(int u,int w,int cst) : u(u),w(w),cst(cst) {}
    bool operator < (const node& p) const
    {
        return w > p.w;
    }
};
map<ii,int > dur;
map<ii,int > cpy_dur;
map<ii,bool> mark;
int cost[50];
vi lift[50];
int main()
{
    //cout<<MAX<<endl;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int a,b;
    a = 10,b=1;

    //tmp.u=a;tmp.z=b;

    int n,k;
    while(scanf("%d %d",&n,&k)==2)
    {
        bool flag = false;
        viii graph[120];
        vii zero;
        for(int i = 1; i<=n; i++)
            scanf("%d",&cost[i]);
        getchar();
        int xx;
        for(int i = 1; i<=n; i++)
        {
            string str;
            getline(cin,str);
            stringstream ss(str.c_str());
            int a;
            while(ss>>a)
            {
                if(a==0)
                {
                    zero.pb(mp(a,i));
                    xx = i;
                }
                //cout<<a<<endl;
                lift[i].pb(a);
            }
            for(int k = 0; k<(int)lift[i].size(); k++)
                for(int l = k+1; l<(int)lift[i].size(); l++)
                {
                    int u = lift[i][k];
                    int v = lift[i][l];

                    int val = cost[i]*abs(v-u);
                    //cout<<cost[i]<<endl;
                    //   cout<<u<<' '<<v<<' '<<val<<endl;
                    graph[u].pb(mp(v,mp(val,i)));
                    graph[v].pb(mp(u,mp(val,i)));
                    dur[mp(u,i)]=2147483000;
                    dur[mp(v,i)]=2147483000;
                }
        }
        cpy_dur = dur;
        int ans = 2147483000;
        for(int z = 0; z<sz(zero); z++)
        {
            priority_queue<node> Q;
            dur = cpy_dur;
            mark.clear();
            int start = zero[z].first;
            int lft = zero[z].second;
            Q.push(node(start,0,zero[z].second));
            dur[mp(start,lft)]=0;
            node tmp;
            int c,d;
            mark.clear();
            while(Q.empty()==false)
            {
                tmp = Q.top();
                Q.pop();
                int cst_u = tmp.w;
                int f1 = tmp.cst;
                int u = tmp.u;
                if(u==k)
                {
                    if(dur[mp(u,f1)] < ans) ans = dur[mp(u,f1)];
                    flag = true;
                    break;
                }
                mark[mp(u,f1)]=true;
                for(int i = 0; i<sz(graph[u]); i++)
                {
                    int v = graph[u][i].first;
                    int f2 = graph[u][i].second.second;
                    int cost_u_v = graph[u][i].second.first;
                    if(mark[mp(v,f2)]==true) continue;
                    if(f2!=f1)
                    {
                        cost_u_v+=60;
                    }
                    if(dur[mp(v,f2)] > dur[mp(u,f1)]  + cost_u_v)
                    {
                        dur[mp(v,f2)] = dur[mp(u,f1)]  + cost_u_v;
                        Q.push(node(v,dur[mp(v,f2)],f2));
                    }
                }
            }
            while(Q.empty()==false) Q.pop();


        }
        if(flag) printf("%d\n",ans);
        else puts("IMPOSSIBLE");
        for(int i = 0; i<=n+3; i++) lift[i].clear();
    }
    return 0;
}

