#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
string sum[55];
bool comp(string a,string b)
{
    return (a+b) > (b+a);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int N;
    while(scanf("%d",&N)==1){
            if(N==0) return 0;

        for(int i = 0;i<N;i++){
            cin>>sum[i];
        }
        sort(sum,sum+N,comp);
        for(int i = 0;i<N;i++){
            cout<<sum[i];
        }
        puts("");
    }
    return 0;

}
