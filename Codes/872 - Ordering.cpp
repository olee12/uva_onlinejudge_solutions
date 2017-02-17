#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
char str[200];
int ind = 0;
bool graph[27][27];
bool taken[50];
vector<int> res;
int cnt;
char input[50];
int no =0;
bool cheak(int ch)
{
    for(int i = 0;i<res.size()-1;i++)
        if(graph[ch][res[i]]==true) return false;
    return true;
}
void call(int start)
{
    if(res.size()==cnt){
        ///do something
        no++;
        printf("%c",res[0]+'A');
        for(int i = 1;i<cnt;i++)
        {
            printf(" %c",res[i]+'A');

        }
        puts("");
        return;
    }
    for(int i = 0;i<cnt;i++)
    {
        if(taken[i]==false )
        {
            taken[i]=true;
            res.push_back(input[i]-'A');
            if(cheak(input[i]-'A'))
            call(start+1);
            taken[i]=false;
            res.pop_back();
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    char ara[50];
    int u,v;
    char cont[200];
    bool flag = false;
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--)
    {
        gets(ara);
       // puts(ara);
        if(flag) puts("");flag = true;
        cnt = 0;
        int len = strlen(ara);
        for(int i = 0; i<len; i+=2)
        {
            input[cnt++]=ara[i];
        }
        input[cnt]='\0';
        sort(input,input+cnt);
        gets(cont);

        memset(taken,false,sizeof taken);
        len = strlen(cont);
        for(int i = 0; i<len; i+=4)
        {
            u = cont[i]-'A';
            ///v y x v
            v = cont[i+2]-'A';
            graph[u][v] = true;
        }
        res.clear();
        no = 0;
        call(0);

        if(no==0) printf("NO\n");
        for(int i = 0;i<27;i++) memset(graph[i],0,sizeof(graph[i]));
        getchar();
   }
    return 0;
}


