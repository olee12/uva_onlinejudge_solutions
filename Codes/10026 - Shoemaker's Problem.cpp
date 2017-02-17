#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class work
{
public:

    int time;
    int fine;
    int num;
};
bool comp(work a, work b)
{
    double c = (double)a.fine/a.time;
    double d = (double)b.fine/b.time;
    if(c!=d) return c>d;
    else return a.num<b.num;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    work ara[1005];
    int test;
    int N;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&N);
        for(int i = 0;i<N;i++){
            scanf("%d %d",&ara[i].time,&ara[i].fine);
            ara[i].num = i+1;
        }
        sort(ara,ara+N,comp);
        for(int i = 0;i<N;i++){
            if(i) printf(" ");
            printf("%d",ara[i].num);
        }
        printf("\n");
        if(test) puts("");
    }
    return 0;
}

