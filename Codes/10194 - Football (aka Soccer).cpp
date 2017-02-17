#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<list>
using namespace std;

typedef struct
{
    int goalscr=0;
    int goalagi=0;
    int goaldiff=0;
    int wins=0;
    int lose=0;
    int tie=0;
    int point=0;
    int gameplayed=0;
    string teamname;
} data;
data ara[1050];
bool comp(data a,data b);
map<string,data> mp;
int main()
{

    int N,T,G,goal_1,goal_2;
    char str[2000];
    string torname;
    string team_1,team_2;
    scanf("%d ",&N);
    //getchar();
    int i,j,k,l,tor,tm,gm;
    while(N--)
    {
        getline(cin,torname);
        // getchar();
        scanf("%d ",&T);
       // getchar();
        for(tm=0; tm<T; tm++)
        {
            // cout<<tm<<endl;
            gets(str);
            for(int l = 0;str[l];l++)
            //cout<<str<<endl;
            mp[str];
        }
        //getchar();
        scanf("%d",&G);
        getchar();
        //cout<<G<<endl;
        for(gm=0; gm<G; gm++)
        {
            // cout<<gm<<endl;
            team_1="";
            team_2="";
            string goal="";
            int g1,g2;
            gets(str);
            for(i =0; str[i]!='#'; i++) team_1+=str[i];
            i++;
            // cout<<team_1<<endl;
            for(; str[i]!='@'; i++) goal+=str[i];
            i++;
            g1 = atoi(goal.c_str());
            mp[team_1].goalscr+=g1;

            goal="";
            for(; str[i]!='#'; i++) goal+=str[i];
            i++;

            for(; str[i]; i++) team_2+=str[i];
            g2 = atoi(goal.c_str());
            mp[team_2].goalscr+=g2;
            //  cout<<team_1<<' '<<team_2<<' '<<g1<<' '<<g2<<endl;
            mp[team_1].goalagi += g2;
            mp[team_2].goalagi += g1;
            mp[team_1].gameplayed++;
            mp[team_2].gameplayed++;
            //mp[team_1].goaldiff = g1-g2;
            //mp[team_2].goaldiff=g2-g1;
            if(g1>g2)
            {
                mp[team_1].wins++;
                mp[team_1].point+=3;
                mp[team_2].lose++;
            }
            else if(g2>g1)
            {
                mp[team_2].point+=3;
                mp[team_2].wins++;
                mp[team_1].lose++;
            }
            else
            {
                mp[team_1].point+=1;
                mp[team_2].point+=1;
                mp[team_1].tie++;
                mp[team_2].tie++;
            }
        }
       // puts("");
        int in=0;
        for(map<string,data> :: iterator it=mp.begin(); it!=mp.end(); it++)
        {
            ara[in].teamname=it->first;
            ara[in].gameplayed=it->second.gameplayed;
            ara[in].goalagi=it->second.goalagi;
            ara[in].goalscr = it->second.goalscr;
            ara[in].goaldiff = it->second.goalscr - it->second.goalagi;
            ara[in].lose = it->second.lose;
            ara[in].point = it->second.point;
            ara[in].tie = it->second.tie;
            ara[in].wins=it->second.wins;
            in++;
            // printf("team name: %s\n goal_scr %d\n tie %d\n wins %d\n point %d\n goal_agi %d\n lose %d\n game_play %d\n diff %d\n",it->first.c_str(),it->second.goalscr,it->second.tie,it->second.wins,it->second.point,it->second.goalagi,it->second.lose,it->second.gameplayed,it->second.goalscr - it->second.goalagi);;
        }
        sort(ara,ara+in,comp);
        cout<<torname<<endl;
        for(int i = 0; i<T; i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,ara[i].teamname.c_str(),ara[i].point,ara[i].gameplayed,ara[i].wins,ara[i].tie,ara[i].lose,ara[i].goalscr - ara[i].goalagi,ara[i].goalscr,ara[i].goalagi);
            // printf("team name: %s\n goal_scr %d\n tie %d\n wins %d\n point %d\n goal_agi %d\n lose %d\n game_play %d\n diff %d\n",ara[i].teamname.c_str(),ara[i].goalscr,ara[i].tie,ara[i].wins,ara[i].point,ara[i].goalagi,ara[i].lose,ara[i].gameplayed,ara[i].goalscr - ara[i].goalagi);
        }
        if(N) printf("\n");
        mp.clear();

    }
    return 0;

}
bool comp(data a,data b)
{
    if(a.point != b.point) return a.point > b.point;
    else if(a.wins != b.wins) return a.wins > b.wins;
    else if(a.goaldiff != b.goaldiff) return a.goaldiff > b.goaldiff;
    else if(a.goalscr != b.goalscr) return a.goalscr > b.goalscr;
    else if( a.gameplayed != b.gameplayed ) return a.gameplayed<b.gameplayed;
    else {
            string c="", d="";
                for(int i = 0;i<a.teamname.size();i++){
                    c+= toupper(a.teamname[i]);
                }
                for(int i = 0;i<b.teamname.size();i++){
                    d+= toupper(b.teamname[i]);
                }
            return  c< d;
    }
}
