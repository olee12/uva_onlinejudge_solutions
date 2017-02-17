#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
string words[110];
int ara[12];
string rool;
int zeros;
int D,R;
int len;
int call(int i,int w)
{
    if(i==zeros)
    {
        int j = 0;
        for(int i = 0; i<len; i++)
        {
            if(rool[i]=='#') cout<<words[w];
            else printf("%d",ara[j++]);
        }
        cout<<endl;
    }
    else
    {
        for(int k = 0; k<10; k++)
        {
            ara[i]=k;
            call(i+1,w);
        }
    }

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    while(scanf("%d",&D)!=EOF)
    {

        printf("--\n");
        getchar();
        for(int i = 0; i<D; i++)
            cin>>words[i];
        scanf("%d",&R);
        getchar();
        for(int i = 0; i<R; i++)
        {
            cin>>rool;
            len = rool.size();
            zeros=0;
            for(int j = 0; j<len; j++) if(rool[j]=='0') zeros++;
            for(int k = 0; k<D; k++)
            {
                call(0,k);
            }
        }
    }
    return 0;
}

