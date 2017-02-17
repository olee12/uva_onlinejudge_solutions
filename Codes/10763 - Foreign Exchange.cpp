
#include <iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fr first
#define sc second
struct data
{
    int from;
    int to;
    data(int a,int b)
    {
        from=a;
        to=b;
    }
};
map<pair<int,int> , int > cheak;
vector<pair<int,int> >vec;


int main()
{


    int tst,i,j,from,to,sz,a,b;
    bool flag=0;
    while(scanf("%d",&tst)&&tst)
    {

        flag=1;
        cheak.clear();
        //memset(flag,0,sizeof(flag));
        vec.clear();
        for(i=0; i<tst; i++)
        {
            scanf("%d %d",&from,&to);
//            vec.push_back(mp(from,to));
            cheak[mp(from,to)]++;
        }

        map<pair<int,int> , int > :: iterator  it;
        for(it = cheak.begin(); it!=cheak.end(); it++)
        {
            a = it->fr.fr;
            b = it->fr.sc;
            // printf("%d %d\n",a,b);
            if(it->sc != cheak[mp(b,a)])
            {
                printf("NO\n");
                flag = 0;
                break;
            }

        }
        if(flag) printf("YES\n");

    }

    return 0;
}
