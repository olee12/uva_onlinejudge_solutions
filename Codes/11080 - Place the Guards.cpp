#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;
#define M 220
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(a,b) memset(a,b,sizeof (a))
int colour[M];
int main()
{

   // freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        vi graph[M];
        int m,n;
        scanf("%d %d",&n,&m);
        for(int i = 0; i<m; i++)
        {
            int u ,v;
            scanf("%d %d",&u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
            //cout<<u<<v<<"\n";
        }
        bool isbi = true;

        memset(colour,5,sizeof colour);
        int ans = 0;
        for(int i = 0; i<M; i++) colour[i]=5;
        for(int i = 0; i<n; i++)
        {
            // cout<<colour[i]<<' ';
            if(colour[i]!=5) continue;
            // cout<<i<<endl;
            int c1=0,c2=0;
            queue<int> Q;
            Q.push(i);
            colour[i] = 0;
            c1++;
            while(!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                //cout<<u;
                for(int i = 0; i<sz(graph[u]); i++)
                {
                    int v = graph[u][i];
                    //cout<<"v "<<v<<endl;
                    if(colour[v]==5)
                    {


                        (colour[v]=1-colour[u])==1?c2++:c1++;
                       // cout<<c1<<' '<<c2<<endl;
                        Q.push(v);
                    }
                    else if(colour[u]==colour[v])
                        isbi = false;

                }
            }
            if(isbi) ans+= (c1 &&  c2) ? min(c1,c2):max(c1,c2);

            else
            {
                ans = -1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
