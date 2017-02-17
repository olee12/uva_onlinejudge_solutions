#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
class score
{
public:
    int slno=1e5;
    int submit=0;
    int panalty=0;
    int solve=0;
    int pos[15]={0};

    int pan_in_hand=0;
    int wr_in_hand=0;
    int tm_no=0;

    int time_wa[15]= {0};
    void set_val(int cons,int prb,int tm, char ch);
    bool operator < (const score& b) const;
};

bool score::operator < (const score& b) const
{
    if(solve!=b.solve) return solve > b.solve;
    else if(panalty != b.panalty) return panalty<b.panalty;
    return slno < b.slno;
}
/*bool comp(score a, score b)
{
    //if(a.solve || b.solve){
    if(a.solve!=b.solve) return a.solve> b.solve;
    else if(a.panalty != b.panalty) return a.panalty< b.panalty;
    //}

   // else if(a.submit || b.submit) //return 1;
        return a.slno < b.slno;
    return 0;
}*/
void score::set_val(int cons,int prb,int tm, char ch)
{
    submit = 1;
    slno = cons;
    if(ch != 'I' && ch!= 'C') return ;
    else if(ch=='I')
    {
        time_wa[prb]++;
        wr_in_hand++;
    }
    else
    {
        if(pos[prb]) return;
        pos[prb] = 1;
        panalty += ((time_wa[prb]*20) + tm);
        solve++;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    char str[1000];
    int test;
    int cons;
    int prb;
    int tm;
    char ch;
    int N;
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--)
    {
        score ara[105];
        N=0;
        while(gets(str))
        {
            if(str[0]=='\0') break;
            sscanf(str,"%d %d %d %c",&cons,&prb,&tm,&ch);
            ara[cons].set_val(cons,prb,tm,ch);

        }
        sort(ara,ara+105);
        for(int i = 0; ara[i].submit; i++)
        {
            printf("%d %d %d\n",ara[i].slno,ara[i].solve,ara[i].panalty);
        }
        if(test) puts("");
    }
    return 0;

}
