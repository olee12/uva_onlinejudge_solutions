#include<cstring>
#include<string>
#include<iostream>
#include<iterator>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int ara[10005];
int freq[10005];
bool func(int& n)
{
    int max_ap  = (n/3)+1;
    for(int i = 1;i<=max_ap;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int now = j;
            int cnt = 0;
            while(cnt<2)
            {
                int s = ara[now]+i;
                if(freq[s]>now)
                {
                    cnt++;
                    now = freq[s];
                }
                else {
                    break;
                }
            }
            if(cnt>=2) return false ;
        }
    }
    return true;

}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    int val;
    char ch;
    while(1)
    {
        scanf("%d",&n);
        if(!n) return 0;
        scanf("%c",&ch);
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&val);
            freq[val] = i;
            ara[i] = val;

        }
        if(func(n))
        {
            puts("yes");
        }
        else puts("no");

    }


}
//https://www.facebook.com/newbasherkella?notif_t=fbpage_fan_invite
