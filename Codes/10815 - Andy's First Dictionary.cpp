#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<set>
#include<cctype>
#include<iterator>
using namespace std;
int main()
{

    string str;
    string ara="";
    set<string> dic;
    while(cin>>str)
    {

        int l = str.size();
        for(int i=0; i<=l; i++)
        {
            if(isalpha(str[i]))
            {
                ara+=tolower(str[i]);
            }
            else if(ara!="")
            {
                dic.insert(ara);

                ara="";
            }
        }

    }
    set<string>::iterator it;
    for(it=dic.begin(); it!=dic.end(); it++) cout<<*it<<endl;
    return 0;
}
