#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<vector>
#include<map>
#include<string>
using namespace std;
typedef vector<int> vi;
#define mem() memset(a,0,sizeof(a))
int sum,N,ara[25],element;
int total;
vi result;
vi tmp_res;
bool taken[25];

int call(int sum,int start)
{
    if(sum>total && sum<=N)
    {
        tmp_res = result;
        total=sum;
        /*cout<<"total : "<<total<<" songs: ";
        for(int i = 0;i<tmp_res.size();i++)
        {
            if(i) cout<<' ';
            cout<<tmp_res[i];
        }
        puts("");*/
    }
    for(int i = start; i<element; i++)
    {
        if(taken[i]==0)
        {
            sum+=ara[i];
            result.push_back(ara[i]);

            call(sum,i+1);
            sum-=ara[i];
            taken[i]=false;
            result.pop_back();

        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    while(cin>>N)
    {
        total = 0,sum = 0;
        result.clear();
        tmp_res.clear();
        cin>>element;
        for(int i = 0; i<element; i++)
            cin>>ara[i];
        call(0,0);
        for(int i = 0;i<(int)tmp_res.size();i++)
        {
            printf("%d ",tmp_res[i]);
        }
        printf("sum:%d\n",total);
    }
    return 0;
}
