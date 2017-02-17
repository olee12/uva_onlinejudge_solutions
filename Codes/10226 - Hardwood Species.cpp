#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    int m,n,i,j,k,l;
    char str[50];
    while(test--)
    {


        map<string,int> mp;

        int all=0;
        while(gets(str) && str[0])
        { string a(str);
            mp[a]++;
            all++;
        }
        for(map<string,int>::iterator it = mp.begin();
                it!=mp.end(); it++)
        {
            cout<<it->first<<' ';
            printf("%.4lf\n",(it->second * 100.)/all);
        }
        if(test) printf("\n");
    }
    return 0;

}
