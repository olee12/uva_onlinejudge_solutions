#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int t,n,mz;
    char str[1000];
    queue<char > Q;

    int j,k,l,count;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        char ara[150]= {0};

        l=0;
        scanf("%d %d ",&n,&mz);
        scanf("%s",str);
        j=mz;
        for(int i =0;i<n; i++)
        {


            if(ara[str[i]])
            {
                l++;
            }
            ara[str[i]]++;
            if(i-j>=0)
            {
                ara[str[i-j]]--;
            }

        }

        printf("Case %d: %d\n",cas++,l);

    }
    return 0;
}
