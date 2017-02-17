#include<bits/stdc++.h>
using namespace std;
char name[20][20];
int sz[20],d[20],ba[20];
int dim[20][20],ind,pos[20];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,r;
    char ara[100];
    scanf("%d %d",&n,&r);
    for(int i = 0;i<n;i++)
    {
        scanf("%s %d %d %d",name[i],ba[i],&sz[i],&d[i]);
        for(int j = 0;j<d[i]*2;j++)
        {
            cin>>dim[i][j];
        }
        for(int i=0;i<r;i++){
            cin>>ara;
            for(int j = 0;j<n;j++) if(ara==name[j]) cout<<j<<endl;
        }
    }

}
