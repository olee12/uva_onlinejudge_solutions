/*#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<iterator>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b);
class assci
{
public:
    int n=0;
    char ch;
} ara[200];
int main()
{
    string str;
    int i,j,k=0,l;
    string flag;
    while(getline(cin,str))
    {
        if(k!=0) cout<<endl;
        k=1;

        l=str.length();
        flag="";
        j=1;
        for(i=0; i<l; i++)
        {
            if(str[i]!=' '|| str[i]!='t'){
            ara[str[i]].n++;
            ara[str[i]].ch=str[i];
            }

        }
        qsort(ara,200,sizeof(assci),comp);
        for(i=0;ara[i].n!=0;i++);
           for(j=i-1;j>=0;j--) { printf("%d %d\n",ara[j].ch,ara[j].n);
        ara[j].n=0;
        ara[j].ch=0;
        }

    }
    return 0;
}
int comp(const void *a,const void *b)
{
    assci *c,*d;
    c = (assci*)a;
    d = (assci*)b;
    if(c->n<d->n)
    {
        return 1;
    }
    else if(c->n>d->n) return -1;
    else
    {
        return c->ch-d->ch;
    }
}
*/
//map , priority_queue , iterator

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<iterator>
#include<list>
#include<set>
#include<algorithm>
#include<string>
#include<cstring>
#include<climits>
#include<numeric>
#include<cmath>
#include<ctime>
using namespace std;

struct ailm{
    int asci,frq;
};
bool comp(ailm x,ailm y)
{
    if(x.frq<y.frq){
        return 1;
    }
    if(x.frq==y.frq&&x.asci>y.asci)
        return 1;
    return 0;

}


int main()
{
    string s;
    int i,j,k,l,f=0,d;
    while(getline(cin,s)){
        int n = s.size();
        if(f!=0) cout<<endl;
        f=1;
        ailm k[1005];
        map<char ,int> mp;
        map<char , int > :: iterator it;
        for(i=0;i<n;i++){
            mp[s[i]]++;
        }
        i=0;
        for(it=mp.begin();it!=mp.end();it++){
            int c=it->first;
            int d=it->second;
            k[i].asci=c;
            k[i].frq=d;
            i++;
        }
        int p=i;
        sort(k,k+p,comp);
         for(i=0; i<p; i++)
            cout<<k[i].asci<<" "<<k[i].frq<<endl;
    }
    return 0;
}
/*97 2
100 3
107 2
108 2
109 1
110 2*/
