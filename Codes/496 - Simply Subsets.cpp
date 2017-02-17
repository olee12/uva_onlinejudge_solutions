#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    string str;
    while(getline(cin,str))
    {
        int num;
        stringstream ss(str.c_str());
        set<int> e,f;
        set<int> temp;
        while(ss>>num) e.insert(num);
        getline(cin,str);
        stringstream zz(str.c_str());
        while(zz>>num) f.insert(num);
        set<int>::iterator it;
        set_intersection(e.begin(),e.end(),f.begin(),f.end(),inserter(temp,temp.begin()));
        bool a = (temp==e);
        bool b = (temp==f);
        if(a&&b)
            printf("A equals B\n");
        else if(a)
            puts("A is a proper subset of B");
        else if(b)
            puts("B is a proper subset of A");
        else if((int)temp.size())
            puts("I'm confused!");

        else puts("A and B are disjoint");

    }
    return 0;
}
