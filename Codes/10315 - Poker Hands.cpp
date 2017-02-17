#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<string>
using namespace std;
struct hand
{
    int hf;
    set<int> for_one_pair;
    int cc,dd,hh,ss;
    int val[10];
    int remaining_22 ;
    int sec_par;
    pair<int,int> final_value;
    void distibution(string str[]);
    void Straight_flush();///9
    void Four_of_a_kind();///8
    void Full_House();///7
    void Flush();///6
    void Straight();///5
    void Three_of_a_Kind();///4
    void Two_Pairs();///3

};
void hand :: distibution(string str[])
{
    cc=dd=hh=ss=0;
    int cnt;
    for(int i = 1; i<=5; i++)
    {
        int sz = str[i].size();
        if(str[i][0]=='A')
            cnt = 14;
        else if(str[i][0]=='K') cnt = 13;
        else if(str[i][0]=='Q') cnt = 12;
        else if(str[i][0]=='J') cnt = 11;
        else if(str[i][0] == 'T') cnt = 10;
        else
        {
            cnt = str[i][0]-'0';
        }
        val[i]=cnt;
        if(str[i][sz-1]=='H') hh++;
        else if(str[i][sz-1]=='D') dd++;
        else if(str[i][sz-1]=='C') cc++;
        else ss++;
    }

    sort(val+1,val+6);
}

void hand :: Straight_flush()
{
    int cnt = 0;
    cnt = val[1];
    if(cc==5 || dd==5 || hh==5 || ss==5)
    {
        for(int i = 1; i<5; i++)
        {
            if(val[i+1]-val[i] != 1)
            {
                Four_of_a_kind();
                return ;
            }
        }
        final_value = make_pair(val[5],9);
        return ;
    }
    Four_of_a_kind();
    return ;
}

void hand :: Four_of_a_kind()
{
    int ara[16]= {0};
    for(int i= 1; i<=5; i++) ara[val[i]]++;
    for(int i = 2; i<=14; i++)
        if(ara[i]==4)
        {
            final_value = make_pair(i,8);
            for(int j = 1; j<=5; j++) if(val[j]!=i) hf = val[j];
            return;
        }

    Full_House();
    return;

}

void hand :: Full_House()
{
    int three=0,two=0;
    int ara[16]= {0};
    for(int i= 1; i<=5; i++) ara[val[i]]++;
    for(int i = 2; i<=14; i++)
    {
        if(ara[i]==3)
        {
            three = i;
        }
        else if(ara[i]==2)
        {
            two = i;
        }
    }
    if(three!=0 && two!=0)
    {
        final_value = make_pair(three,7);
        hf = two;
        return;
    }
    Flush();
    return;

}
void hand :: Flush()
{
    if(cc==5 || hh==5 || dd==5 || ss==5)
    {
        final_value = make_pair(-1,6);
        for(int i = 1; i<=5; i++)
        {
            for_one_pair.insert(val[i]);
        }
        return ;
    }
    Straight();
    return ;
}

void hand :: Straight()
{
    for(int i = 1; i<5; i++)
    {
        if(val[i+1] - val[i] != 1)
        {
            Three_of_a_Kind();
            return ;
        }
    }
    final_value = make_pair(val[5],5);
    return ;

}
void hand :: Three_of_a_Kind()
{
    int ara[16]= {0};
    for(int i = 1; i<=5; i++) ara[val[i]]++;
    for(int i = 2; i<=14; i++)
        if(ara[i]==3)
        {
            final_value = make_pair(i,4);
            for(int j = 1; j<=5; j++) if(val[j]!=i) for_one_pair.insert(val[j]);
            return;
        }
    Two_Pairs();
}

void hand :: Two_Pairs()
{
    int a=0,b=0;
    int ara[16]= {0};
    for(int i = 1; i<=5; i++) ara[val[i]]++;
    for(int i = 2; i<=14; i++)
    {
        if(ara[i]==2 && a==0)
        {
            a = i;
        }
        else if(ara[i]==2 && b==0)
        {
            b = i;
        }
    }
    if(a!=0 && b!=0)
    {
        final_value = make_pair(b,3);
        sec_par=a;
        for(int i = 1; i<=5; i++)
        {
            if( val[i]!=a || val[i]!=b ) remaining_22 = val[i];

        }
        return;
    }
    else if( a!=0 && b==0)
    {
        final_value = make_pair(a,2);
        for(int i = 1; i<=5; i++) if(a!=val[i]) for_one_pair.insert(val[i]);

        return ;
    }
    final_value = make_pair(-1,1);
    for(int i = 1; i<=5; i++) for_one_pair.insert(val[i]);
    return ;

}

string One_pair_tie(set<int> b,set<int> w)
{
    set<int> :: iterator it_w,it_b;
    it_b = b.end();
    it_w=w.end();
    it_w--;
    it_b--;
    for(;; it_b--,it_w--)
    {
        if(*it_b>*it_w) return "Black wins.";
        else if (*it_b < *it_w) return "White wins.";
        if(it_b==b.begin()) break;
    }
    return "Tie.";
}
int main()
{
    string s1[6];
    string s2[6];
    while(cin.peek()!=EOF)
    {
        while(cin>>s1[1]>>s1[2]>>s1[3]>>s1[4]>>s1[5]>>s2[1]>>s2[2]>>s2[3]>>s2[4]>>s2[5])
        {
            hand black,white;
            black.distibution(s1);
            white.distibution(s2);
            black.Straight_flush();
            white.Straight_flush();
            int b_val = black.final_value.first;
            int b_rank = black.final_value.second;
            int w_val = white.final_value.first;
            int w_rank = white.final_value.second;
            if(b_rank==1 && w_rank==1) cout<<One_pair_tie(black.for_one_pair,white.for_one_pair)<<endl;
            else if(b_rank==6 && w_rank==6)
            {
                cout<<One_pair_tie(black.for_one_pair,white.for_one_pair)<<endl;
            }
            else if(b_rank==2 && w_rank==2)
            {


                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else if(b_val==w_val)
                {
                    cout<<One_pair_tie(black.for_one_pair,white.for_one_pair)<<endl;
                }
            }
            else if(b_rank==4 && w_rank==4)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else if(b_val==w_val)
                {
                    cout<<One_pair_tie(black.for_one_pair,white.for_one_pair)<<endl;
                }
            }
            else if(b_rank==3 && w_rank==3)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else if(black.sec_par > white.sec_par) puts("Black wins.");
                else if(black.sec_par < white.sec_par) puts("White wins.");
                else if(black.remaining_22>white.remaining_22) puts("Black wins.");
                else if(black.remaining_22<white.remaining_22) puts("White wins.");
                else puts("Tie.");
            }
            else if(b_rank==5 && w_rank==5)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else puts("Tie.");
            }
            else if(b_rank==7 && w_rank==7)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else if(black.hf>white.hf) puts("Black wins.");
                else if(black.hf<white.hf) puts("White wins.");
                else puts("Tie.");
            }
            else if(b_rank==8 && w_rank==8)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else if(black.hf>white.hf) puts("Black wins.");
                else if(black.hf<white.hf) puts("White wins.");
                else puts("Tie.");
            }
            else if(b_rank==9 && w_rank==9)
            {
                if(b_val>w_val) puts("Black wins.");
                else if(b_val < w_val) puts("White wins.");
                else puts("Tie.");
            }
            else if(b_rank> w_rank ) puts("Black wins.");
            else if(b_rank<w_rank) puts("White wins.");
        }
    }
    return 0;
}
