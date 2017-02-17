#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
struct res
{
    int s,r;
    int dif;
    bool operator < (const res& p) const
    {
        return dif < (p.dif);
    }
};
res ara[100005];
int main()
{
    //freopen("input.txt","r",stdin);
    int n,goal;
    int r,s;
    while(scanf("%d %d",&n,&goal)==2)
    {
        int ind = 0;
        int point=0;
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d",&s,&r);
            if(s>r) point+=3;
            else if(r==s)
            {
                if(goal)
                {
                    goal--;
                    point+=3;
                }
                else point+=1;
            }
            else
            {
                ara[ind].r=r;
                ara[ind].s=s;
                ara[ind].dif = r-s;
                ind++;
            }
        }
        sort(ara,ara+ind);
        for(int i = 0; i<ind; i++)
        {
            if(ara[i].dif <= (goal - 1))
            {
                point+=3;
                goal-=(ara[i].dif+1);
            }
            else if(ara[i].dif == goal)
            {
                point+=1;
                goal = 0;
            }
            else break;
        }
        printf("%d\n",point);

    }
    return 0;

}
