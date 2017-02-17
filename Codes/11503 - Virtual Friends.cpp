#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
int par[100005];
int cnt[100005];
map <string , int > name;
void makeset(int n);
int find_par(int r)
{

    if(par[r]==0) return r;
    if(r==par[r]) return r;

    return par[r]=find_par(par[r]);
}
void Union(int a,int b)
{
    par[find_par(a)]=par[find_par(b)];
}
int main()
{
    #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    string str1,str2;
    int a,b;
    int i ,j,k,l;
    int test;
    int f;
    int lol=1;
    scanf("%d",&test);
    while(test--){
            int m = 1;
        int xx=1;
        scanf("%d",&f);
        for(i = 0;i < f;i++){
            cin>>str1>>str2;
            if(!name[str1]) {
                a=name[str1]=xx++;
               // cout<<str1<<" : "<<xx-1<<endl;
               // par[a]=a;
            }
            if(!name[str2]){
                b=name[str2]=xx++;
               // cout<<str2<<" : "<<xx-1<<endl;
               //par[b]=b;
            }

            a = find_par(name[str1]);
            b = find_par(name[str2]);
            if(a!=b){
                par[a]=b;
                cnt[b]=(cnt[a]?cnt[a]:1) + (cnt[b]?cnt[b]:1);
                printf("%d\n",cnt[b]);
            }
            else{
                printf("%d\n",cnt[a]);
            }
            /*Union(a,b);
            int e = find_par(a);
            int f = find_par(b);
            printf("%d %d\n%d %d\n",e,f,name[str1],name[str2]);
            if(e>f) e^=f^=e^=f;
            int frnd = 0;
            for(int l = 1;l<xx;l++){
                if(f == find_par(l)) frnd++;
            }

            cout<<"case "<< lol++<<" : ";
            cout<<frnd<<endl;;

            cout<<"xx = "<<xx<<endl;
           // cout<<find_par()
            for(int k = 1;k<xx;k++){
                    cout<<"find_par("<<k<<") :"<<find_par(k)<<endl;
                cnt[find_par(k)]++;
            }
            //for(int k = 1;k<xx;k++) cout<<' '<<cnt[k];
            //cout<<endl;
            for(int k = 1;k<xx;k++){
                m = max(m,cnt[k]);
            }
            //cout<<cnt[name[str2]]<<endl;*/

        }
        memset(par,0, sizeof par);
        memset(cnt,0,sizeof cnt);
        name.clear();
    }
    return 0;
}

