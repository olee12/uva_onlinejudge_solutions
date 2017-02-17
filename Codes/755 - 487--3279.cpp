#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 120000
#define sf scanf
#define pf printf

///A, B, and C map to 2

///D, E, and F map to 3

///G, H, and I map to 4

///J, K, and L map to 5

///M, N, and O map to 6

///P, R, and S map to 7

///T, U, and V map to 8

///W, X, and Y map to 9
char ara[200];
int main()
{

    ara['2'] = ara['A']=ara['B']=ara['C'] = '2';
    ara['3'] = ara['D']=ara['E']=ara['F'] = '3';
    ara['4'] = ara['G']=ara['H']=ara['I'] = '4';
    ara['5'] = ara['J']=ara['K']=ara['L'] = '5';
    ara['6'] = ara['M']=ara['N']=ara['O'] = '6';
    ara['7'] = ara['P']=ara['R']=ara['S'] = '7';
    ara['8'] = ara['T']=ara['U']=ara['V'] = '8';
    ara['9'] = ara['W']=ara['X']=ara['Y'] = '9';
    ara['0'] = '0';
    ara['1'] = '1';
    int test;
    char str[500];
    char phn[12];

    int n;
    int cnt =0;

    sf("%d",&test);
    char t1,t2;
    bool f;
    while(test--)
    {
        map<string,int> phone_book;
        scanf("%d",&n);
        f=true;
        while(n--)
        {
            scanf("%s",str);
            int len = strlen(str);
            cnt = 0;
            for(int i = 0; i<len; i++)
            {
                if(ara[str[i]]==0) continue;
                phn[cnt++]=ara[str[i]];
            }
            phn[cnt+1]='\0';
            for(int i = cnt-1; i>=3; i--)
                phn[i+1]=phn[i];
            phn[3]='-';
            phone_book[phn]++;
        }
        map<string,int> :: iterator it = phone_book.begin();
        for(; it!=phone_book.end(); it++)
        {
            if(it->sc>1)
            {
                pf("%s %d\n",it->fr.c_str(),it->sc);
                f=false;
            }
        }
        if(f) puts("No duplicates.");
        if(test) puts("");
    }
    return 0;

}





