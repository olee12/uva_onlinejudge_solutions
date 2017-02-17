#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
#include<set>
using namespace std;

map<string,int> name;
map<int,vector<int> > edge;
int disten[5000];

void bfs(int start)
{
    memset(disten,-1,sizeof disten);
    queue<int> Q;

    disten[start]=0;
    int u , v;
    Q.push(start);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        vector<int> :: iterator it;
        for(it=edge[u].begin(); it!=edge[u].end(); it++)
        {
            v = *it;
            if(disten[v]<0)
            {

                disten[v]=disten[u]+1;
                Q.push(v);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDEG
    int p,n;
    string str;

    int test;
    scanf("%d",&test);
    int coma;
    for(int sen = 1; sen<=test; sen++)
    {
         int xx=1;

        string temp="";
        scanf("%d %d ",&p,&n);
        for(int i = 0; i<p; i++)
        {
            vector<string> ara;
            //getchar();
            getline(cin,str);
            //cout<<str<<endl;
            int x = 0;
            for(int j = 0,coma=0; str[j]!=':'; j++)
            {
                if(str[j]==',') coma++;
                if(coma%2==0 && coma)
                {
                    //cout<<j<<endl;
                    ara.push_back(temp);
                    //  cout<<temp<<endl;
                    temp="";
                    coma=0;
                    j++;

                }
                else
                {
                    temp+=str[j];
                    //cout<<j<<endl;
                }

            }
            ara.push_back(temp);
            // cout<<temp<<endl;
            temp="";

            for(int i = 0; i<ara.size(); i++)
            {
                if(name.find(ara[i])==name.end()){

                 name[ara[i]]=xx++;
                }
            }
            for(int k = 0; k<ara.size(); k++)
            {
                for(int l = k+1; l<ara.size(); l++)
                {
                    int a1 = name[ara[k]];
                    int a2 = name[ara[l]];
                    edge[a1].push_back(a2);
                         edge[a2].push_back(a1);
                }
            }
        }
        bfs(name["Erdos, P."]);
        printf("Scenario %d\n",sen);
       // cout<<disten[name["Hsueh, Z."]]<<endl;
        for(int i = 0; i<n; i++)
        {
            getline(cin,str);
            if(disten[name[str]]>=0) printf("%s %d\n",str.c_str(),disten[name[str]]);
            else printf("%s infinity\n",str.c_str());
        }
        name.clear();
        edge.clear();

    }
    return 0;


}

