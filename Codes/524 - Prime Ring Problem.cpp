#include<iostream>
#include<vector>
#include<iterator>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
#define M 40
bool flag[M];
int prime[M];
int c = 0;
int n;
void sieve()
{
    flag[2]=0;
    flag[3]=0;
    register int i,j,add;
    for(i = 4; i<M; i+=2) flag[i]=true;
    for(i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {
            if(M/i>=i)
            {
                add = i*2;
                for(j = i*i; j<M; j+=add)
                    flag[j]=true;
            }
        }
    }
}
vector<int> res;
bool taken[20];
int ara[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
bool cheak()
{
    int a,b;
    for(int i = 0; i<res.size()-1; i++)
    {
        a = res[i];
        b = res[i+1];
        b +=a;
        if(flag[b]!=false) return false;
    }
    if(res.size()==n)
    {
        a = res[0];
        b = res[n-1];
        b+=a;
        if(flag[b]!=false) return false;
    }
    return true;
}


void call()
{

    if(res.size()==n)
    {
        ///do something

        {
           // printf("%d",res[0]);

            for(int i = 1; i<n; i++)
            {
             //   printf(" %d",res[i]);
            }
          //  puts("");
        }

        return ;
    }
    for(int i = 1; i<n; i++)
    {
        if(taken[i]==false)
        {
            taken[i]=true;
            res.push_back(ara[i]);
            if(cheak())
            {
                call( );
            }
            taken[i]=false;
            res.pop_back();
        }
    }
}


int main()
{
    sieve();
    int cas = 1;
    //for(int i=  0; i<20; i++) cout<<prime[i]<<endl;
    bool f = false;
    while(scanf("%d",&n)==1)
    {
        //cout<<n<<endl;
        if(f) puts("");
        f = true;
        memset(taken,false,sizeof taken);
        res.clear();
        res.push_back(1);
        printf("Case %d:\n",cas++);
        call( );

    }
    return 0;

}

