#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int func(int n);
int main()
{
    int m,n;

    while(cin>>m>>n)
    {
        if(m==0 && n==0) break;
        int count=0;
        for(int i=m; i<=n; i++)
        {
            if(func(i))
                count++;
        }
        cout<<count<<endl;
    }
    return 0;

}
int func(int n)
{
    map<int , int > ma;
    int m;
    while(n)
    {
        m = n%10;
        n/=10;
        ma[m]++;

        if(ma[m]==2) return 0;
    }
    return 1;
}
/*
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int ara[5010]={0};
    int n,m;
    int i,j,k;
    int count;
    while(scanf("%d %d",&m,&n)){
            map< int ,int > str;
            count=0;
        for(i=m;i<=n;i++){
            str[i]++;


        }
        for(i=m;i<=n;i++){
            if(str[i]>1) continue;
            count++;
        }
        printf("%d\n",count);


    }

}*/
