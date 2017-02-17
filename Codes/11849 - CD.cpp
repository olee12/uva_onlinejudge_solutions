#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    int M,N;
    int i,j,k,l;
    long long  int val;

    while(scanf("%d %d",&N,&M))
    {
        if(N==0 && M==0) break;
        set< long long int > s;
        for(i=0; i<N; i++)
        {
            scanf("%lld",&val);
            s.insert(val);

        }
        for(i=0; i<M; i++)
        {
            scanf("%lld",&val);
            s.insert(val);

        }
        cout<<N+M-s.size()<<endl;

    }
    return 0;
}
