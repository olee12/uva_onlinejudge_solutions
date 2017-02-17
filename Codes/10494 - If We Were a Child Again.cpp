#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define M 1000000
typedef long long ll;
ll call_dev(char *number,ll dev,char *result)
{
    ll len = strlen(number);
    ll now;
    ll extra;
    char res[M];
    for(now = 0,extra = 0; now<len; now++)
    {
        extra = extra*10 +(number[now]-'0');
        res[now] = extra/dev + '0';
        extra%=dev;
    }
    res[now]='\0';
    now = 0;
    while(res[now]=='0') now++;
    strcpy(result,&res[now]);
    if(strlen(result)==0) strcpy(result,"0");
    return extra;
}
int main()
{
   // freopen("input.txt","r",stdin);
    char fir[M],res[M];
    ll sec,reminder;
    char ch;
    while(scanf("%s %c %lld",fir,&ch,&sec)==3)
    {
        reminder = call_dev(fir,sec,res);
        if(ch=='/') puts(res);
        else printf("%lld\n",reminder);
    }
    return 0;
}
