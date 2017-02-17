#include<bits/stdc++.h>
using namespace std;
char name[20][20];
int sz[20],d[20],ba[20];
int dim[20][20],ind,pos[20];
void solve()
{
    int i,j,k,l[20],pos1[20],n,m,lim;
    int address;
    k = d[ind];
   // cout<<k<<endl;
    m = 0;
    lim = k*2;
    for(j = 0;j<lim;j+=2) {

        pos1[m]=pos[m]-dim[ind][j];
        m++;
    }
    m = 0;
    for(j = 0;j<lim;j+=2){

        l[m++]=dim[ind][j+1]-dim[ind][j]+1;
        //cout<<l[m-1]<<endl;;
    }
  //  cout<<k<<endl;
    //cout<<m<<endl;
    if(k==1) address = pos1[0];
    else if(k == 2) {
       address = pos1[0]*l[1]+pos1[1];
     //  cout<<pos[0]<<' '<<l[1]<<' '<<pos1[1]<<endl;
    }
    else {
        address = pos1[0]*l[1]+pos1[1];

        for(i = 2;i<k;i++){
            address = address * l[i]+pos1[i];
        }
    }
    //cout<<address<<endl;
    address = sz[ind]*address + ba[ind];
    printf("%s[",name[ind]);
    for(i=0;i<k;i++){
         if(i) printf(", ");
        printf("%d",pos[i]);

    }
     printf("] = %d\n",address);
     ;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n,r;
    char ara[100];
    scanf("%d %d",&n,&r);
    getchar();
   // cout<<n<<' '<<r<<endl;
    int i,j;
    for(i = 0; i<n; i++)
    {
        scanf("%s %d %d %d",name[i],&ba[i],&sz[i],&d[i]);
       // cout<<name[i]<<endl;
        for(j = 0; j<d[i]*2; j++)
        {
            cin>>dim[i][j];
           // cout<<dim[i][j]<<endl;
        }

    }
    getchar();

    for(i=0; i<r; i++)
    {
        scanf("%s",ara);

       // cout<<ara<<' '<<i<<endl;
        for( j = 0; j<n; j++) if(!strcmp(ara,name[j])) break;
        int k = d[j];
        ind = j;
        for( j = 0;j<k;j++) scanf("%d",&pos[j]);
        solve();
    }
    return 0;

}

