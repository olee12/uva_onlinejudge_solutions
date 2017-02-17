#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int par[10005];
int find_par(int r)
{
    if(par[r]==0) return r;
    if(r==par[r]) return r;
    return par[r] = find_par(par[r]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;
    int N;
    int l;
    int yes,no;
    int a,b;
    char ch;
    int u,v;
    char str[500];
    scanf("%d",&test);
    int x = 0;
    while(test--){
        yes=0;
        no = 0;
        scanf("%d",&N);
        getchar();
        while(gets(str)){

            for(l = 0;str[l];l++);
            if(!l) break;
            sscanf(str,"%c %d %d",&ch,&a,&b);
           // printf("%c %d %d\n",ch,a,b);
            if(ch == 'c'){
                u = find_par(a);
                v = find_par(b);
                if(u!=v) par[u]=v;
            }
            if(ch=='q'){
                    int e = find_par(a);
                    int f = find_par(b);
                    //cout<<e<<' '<<f<<endl;

                if( e==f ) yes++;
                else no++;
            }
        }
        if(x) puts("");
        x=1;
        printf("%d,%d\n",yes,no);
        memset(par,0,sizeof par);

    }
    return 0;
}
