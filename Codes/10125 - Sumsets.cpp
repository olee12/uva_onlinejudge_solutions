#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iterator>
#include<iostream>
using namespace std;
#define MAX 536870950
int ara[1050];
int sz;
int findd()
{
    int a,b,c,d;
    for(d=sz-1;d>=0;d--)
        for(a=0;a<sz;a++)
        for(b=a+1;b<sz;b++)
        for(c=b+1;c<sz;c++)
        if((ara[d] == ara[a]+ara[b]+ara[c]) && a!=d && b!=d && c!=d ) return ara[d];



    return MAX;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(scanf("%d",&sz) && sz){
        for(int i = 0;i<sz;i++){
            scanf("%d",&ara[i]);

        }
        sort(ara,ara+sz);
        int d = findd();
        if(d == MAX) printf("no solution\n");
        else printf("%d\n",d);
    }
    return 0;

}

