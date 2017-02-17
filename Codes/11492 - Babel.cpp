#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define M 4005
struct node
{
    int u,w,head;
    node(int u,int w,int head) : u(u),w(w),head(head) {}
    bool operator < (const node& p) const
    {
        return w > p.w;
    }
};
int xx;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    string from,to,s1,s2,word;
    while(scanf("%d",&test)==1 && test)
    {
        vector<int> graph[M],d[M],letter[M];
        map<string,int> str_num;
        xx=1;
        cin>>from>>to;
        for(int i = 0; i < test; i++)
        {
            cin>>s1>>s2>>word;
            if(str_num.find(s1)==str_num.end())
                str_num[s1]=xx++;

            if(str_num.find(s2)==str_num.end())
                str_num[s2]=xx++;
            int u = str_num[s1];
            int v = str_num[s2];
            graph[u].push_back(v);
            graph[v].push_back(u);
            d[u].push_back(word.size());
            d[v].push_back(word.size());
            letter[u].push_back(word[0]-'a');
            letter[v].push_back(word[0]-'a');

        }
        if(from==to)
        {
            puts("0");
        }
        else if(str_num.find(from)==str_num.end()||str_num.find(to)==str_num.end())
        {
            puts("impossivel");
            continue;
        }
        else
        {
            priority_queue<node> Q;
            int dist[M][26];
            for(int i = 0; i<M; i++)
                fill(dist[i],dist[i]+26,1e8);
            Q.push(node(str_num[from],0,-1));
            while(Q.empty()==false)
            {
                node tmp = Q.top();
                Q.pop();
                int u = tmp.u;
                for(int i = 0; i<graph[u].size(); i++)
                {
                    int head = letter[u][i];
                    int v = graph[u][i];
                    if(tmp.head!=head && dist[v][head] > tmp.w + d[u][i])
                    {
                        dist[v][head] = tmp.w + d[u][i];
                        Q.push(node(v,dist[v][head],head));
                    }
                }
            }
            int ans = 1e8;
            for(int i = 0; i<26; i++)
            {
                ans = min(ans,dist[str_num[to]][i]);
            }
            if(ans>=1e8) puts("impossivel");
            else
                printf("%d\n",ans);
        }

    }
    return 0;
}

