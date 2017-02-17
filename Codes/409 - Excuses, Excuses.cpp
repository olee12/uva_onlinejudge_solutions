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
#include<sstream>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 10000
#define sf scanf
#define pf printf
#define INF 2061109567
map<string,int> kye;
map<string,int> exe;
int cnt(string s)
{
    int len = s.size();
    char str[100];
    int n = 0;
    int num = 0;
    int x,y;
    string tmp;
    for(int i = 0; i<len; i++)
    {
        n=0;
        //cout<<i<<endl;
        if(isalpha(s[i]))
        {
           y= x=i;
            str[n++]=tolower(s[i]);
            i++;
            while(isalpha(s[i])) str[n++]=tolower(s[i++]);
            tmp = s.substr(x,n);
            for(int k = 0;k<tmp.size();k++) tmp[k]=tolower(tmp[k]);
            str[n]='\0';
            if(kye.find(string(tmp))!=kye.end()) num++;
            //puts(str);
            i--;
        }

    }
    return num;
}
int main()
{

    char str[100];
    int k,s;
    int cas = 1;
    while(sf("%d %d",&k,&s)!=EOF)
    {

        kye.clear();
        exe.clear();
        for(int i = 0; i<k; i++)
        {
            sf("%s",str);
            kye[string(str)]++;
        }
        getchar();
        for(int i = 0; i<s; i++)
        {
            gets(str);
           // puts(str);
            exe[string(str)];
        }
        map<string,int> :: iterator  it;
        it = exe.begin();
        int best=0,tmp;
        for(; it!=exe.end(); it++)
        {
            tmp = cnt(it->first);
           // cout<<it->first<<' '<<tmp<<endl;


            it->sc=tmp;
            best = max(tmp,best);
        }
        pf("Excuse Set #%d\n",cas++);
        for(it=exe.begin(); it!=exe.end(); it++)
        {
            if(it->sc==best) puts(it->fr.c_str());
        }
        puts("");
    }
    return 0;
}
