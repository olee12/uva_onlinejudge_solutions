#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<memory.h>
using namespace std;
#define M 8

int main()
{
    //freopen("input.txt","r",stdin);
    int red[10],green[10],yello[10];
    double dist[10];
    int speeds[65];

    int n;
    int cas = 1;
    while(scanf("%d",&n)==1)
    {
        if(n==-1) break;
        // cout<<n<<endl;
        memset(speeds,0,sizeof speeds);
        for(int i = 0; i<n; i++)
        {
            // cout<<i<<' '<<n;
            cin>>dist[i]>>green[i]>>yello[i]>>red[i];
            // cout<<dist[i]<<green[i]<<yello[i]<<red[i]<<endl;
        }
        bool f = false;
        // cout<<"ouut\n";
        for(int i = 30; i<=60; i++)
        {
            // cout<<"in\n";
            //cout<<i<<endl;

            bool flag = true;
            for(int j = 0; j<n; j++)
            {
                double location = dist[j]*3600/i;
                int total = red[j]+green[j]+yello[j];
                double timing = fmod(location,total);
                if(timing >(green[j]+yello[j]) && timing < total)
                {
                    flag = false ;
                    break;
                }
            }
            if(flag) speeds[i] = 1;
        }

        printf("Case %d:",cas++);
        // return 0;
        bool c = false;
        for(int i = 30; i<=60;)
        {

            // cout<<"dfasdfa\n";
            if(speeds[i])
            {
                f = true ;
                int hi = i,lo = i;
                while(speeds[i] && i<=60)
                    hi = i++;
                if(c) printf(",");
                c = true;
                if(hi == lo)printf(" %d",hi);
                else printf(" %d-%d",lo,hi);
            }
            else
            i++;
        }


        if(f==false) printf(" No acceptable speeds.");
        puts("");

    }
    return 0;
}
