#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<int> se;
    multiset<int> it;
    int t,n,m,a;
    scanf("%d",&t);
    int i,j,k;
    int ans;
    while(t--)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++) {
            scanf("%d",&a);
            se.insert(a);
        }
        for(i=0;i<m;i++){
            scanf("%d",&a);
            if(se.find(a) != se.end() ) se.erase(a);
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;


}
