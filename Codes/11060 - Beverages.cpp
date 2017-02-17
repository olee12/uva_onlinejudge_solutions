#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>
using namespace std;

map<string,int > pre;
map<string ,int > taken;
bool comp(string a,string b)
{
    return pre[a]< pre[b];
}
int main()
{
    int c=1;
    int n,m;
    string name;
    string b1,b2;
    while(scanf("%d",&n)==1)
    {
        map<string,vector<string> > graph;
        vector<string> zero;
        vector<string> order;
        map<string,int> indegree;
        pre.clear();
        taken.clear();
        int o=1;
        for(int i = 0; i<n; i++)
        {
            cin>>name;
            order.push_back(name);
            pre[name]=o++;
            indegree[name];
        }
        cin>>m;
        for(int i = 0; i<m; i++)
        {
            cin>>b1>>b2;

            graph[b1].push_back(b2);
            indegree[b2]++;

        }



        /* for(map<string,vector<string> >::iterator it = graph.begin();it!=graph.end();it++){
             cout<<it->first<<" :";
             sort(it->second.begin(),it->second.end(),comp);
             for(int i = 0;i<it->second.size();i++) cout<<' ' <<it->second[i];
             cout<<endl;
         }*/

        for(int i = 0; i<order.size(); i++)
        {

            for(int j = 0; j < order.size(); j++)
            {
                string p = order[j];
                if(indegree[p]==0 && taken[p]==0)
                {
                    taken[p]=1;
                    zero.push_back(p);
                    for(int k = 0; k<graph[p].size(); k++)
                    {
                        if(taken[graph[p][k]]==0 )
                        {
                            indegree[graph[p][k]]--;
                        }
                    }
                    break;
                }

            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",c++);

        for(int i = 0; i<zero.size(); i++)
        {
            cout<<' '<<zero[i];
        }
        printf(".\n\n");

    }
    return 0;

}
/*for(map<string,int> ::iterator it = indegree.begin(); it!=indegree.end(); it++)
        {
            cout<<it->first<<' '<<it->second<<endl;
            if(it->second == 0)
            {
                //cout<<it->first<<endl;
                zero.push_back(it->first);
            }
        }
        string p,q;
        for(int i = 0; i<zero.size(); i++)
        {
            p = zero[i];
            for(int j = 0; j<graph[p].size(); j++)
            {
                q = graph[p][j];
                indegree[q]--;
                if(indegree[q]==0)
                {
                    zero.push_back(q);
                }
            }
        }
        for(int i = 0;i<zero.size();i++){
            cout<<' '<<zero[i];
        }
        cout<<endl;*/
/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>


#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>


#define getint(a) scanf("%d", &a)
#define loop(i, n) for(int i=0; i<n; i++)
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define pb(a) push_back(a)
#define SZ size()



using namespace std;


map<string, int> pos;

struct compare{
    bool operator () (string a, string b)
    {
        return pos[a] > pos[b];
    }



};

vector<string>beverages;

map<string, vector<string> > graph;
map<string, int>weight;
priority_queue<string, vector<string>, compare> zeroWeight;
vector<string>list;




int main()
{
    string p, q;
    int *point;


    int kaseno = 0;
    int bevarage_number, connections;


    while(getint(bevarage_number) == 1)
    {
        weight.clear();

        while(zeroWeight.SZ)
        {
            zeroWeight.pop();
        }
        list.clear();


        beverages.clear();
        graph.clear();
        loop(i, bevarage_number)
        {
            cin>>p;
            beverages.pb(p);
            pos[p] = i;
        }
        getint(connections);
        loop(i, connections)
        {
            cin>>p;
            cin>>q;
            graph[p].pb(q);
            weight[q]++;
        }

        loop(i, bevarage_number)
        {
            p = beverages[i];
            if(weight[p] == 0)
            {
                zeroWeight.push(p);
            }
        }

        loop(i, bevarage_number)
        {
            p = zeroWeight.top();
            zeroWeight.pop();
            list.pb(p);
            loop(j, graph[p].SZ)
            {
                q = graph[p][j];
                point = &weight[q];
                (*point)--;
                if(*point == 0)
                {
                    zeroWeight.push(q);
                }

            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order: %s", ++kaseno, list[0].c_str());
        FOR(i, 1, bevarage_number)
        {
            cout<<" "<<list[i];
        }
        printf(".\n\n");

    }

}*/
