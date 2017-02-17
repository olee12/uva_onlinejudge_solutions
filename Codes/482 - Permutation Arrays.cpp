#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define M 1000009
struct data
{
    char str[20];
};
data ara[M];
int pos[M];

int main()
{
    //freopen("input.txt","r",stdin);
    bool  f = false;
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    char inp[M];
    while(test--)
    {
        //getchar();
        gets(inp);
        stringstream ss(inp);
        int n = 0;
        if(f) puts("");f = true;
        int a;
        while(ss>> a) pos[n++]=a;
        //cout<<n<<endl;
         for(int i = 0;i<n;i++){
            scanf("%s",ara[pos[i]].str);
           // cout<<pos[i]<<endl;
         }
         for(int i = 1;i<=n;i++){
            printf("%s\n",ara[i].str);
         }
         getchar();
         getchar();
    }
    return 0;
}
