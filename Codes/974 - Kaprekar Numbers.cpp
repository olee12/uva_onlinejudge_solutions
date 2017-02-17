#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
#include<iostream>
bool Kaprekar(int xx)
{
    char tmp[100];
    sprintf(tmp,"%d",xx*xx);
    // puts(tmp);
    string str(tmp);
    for(int i = 1; i<str.length(); i++)
    {
        string s1 = str.substr(0,i);
        string s2 = str.substr(i);
        //cout<<s1<<' '<<s2<<endl;
        int a = atoi(s1.c_str());
        int b = atoi(s2.c_str());
        if(a&&b)
            if(a+b == xx) return 1;
    }
    return 0;
}
int ara[]=
{
    9,
    45,
    55,
    99,
    297,
    703,
    999,
    2223,
    2728,
    4879,
    4950,
    5050,
    5292,
    7272,
    7777,
    9999,
    17344,
    22222,
    38962,
};
int main()
{
    // freopen("out.txt","w",stdout);
    int test;
    int hi,lo;
    int f = 0;
    bool flag;
    scanf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        flag = false;
        if(f) puts("");
        f=1;
        printf("case #%d\n",cas);
        scanf("%d %d",&lo,&hi);
        for(int i = 0; i<19; i++)
        {
            if(ara[i]>=lo && ara[i]<=hi)
            {
                flag = true;
                printf("%d\n",ara[i]);
            }
        }
        if(flag==false)
        printf("no kaprekar numbers\n");
    }
    return 0;
}
