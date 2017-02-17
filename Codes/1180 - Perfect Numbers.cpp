#include<bits/stdc++.h>
using namespace std;
int A[] = {2, 3, 5, 7, 13, 17, 31, 61, 89};
int main()
{
    map<int,int> mp;
    for(int i = 0;i<9;i++)
        mp[A[i]]=1;
    int n,a;
    bool flag;
    while(scanf("%d",&n)==1){
        for(int i = 0;i<n;i++){
            scanf("%d",&a);
            flag = mp[a];
            cout<<(flag?"Yes":"No")<<endl;
            getchar();
        }
    }
    return 0;
}
