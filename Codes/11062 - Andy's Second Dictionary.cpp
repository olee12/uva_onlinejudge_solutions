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
    string str2;
    string ara2;
    string str;
    string ara="";
    set<string> dic;
    while(cin>>str)
    {
        int i=0;

        int l = str.size();
        while(str[l-1]=='-')
        {

            for(; i<=l-1; i++)
            {
                if(isalpha(str[i]))
                {
                    ara+=tolower(str[i]);
                }
                //cout<<ara<<endl;
            }
            cin>>str;
            l = str.size();
            i=0;

        }



        for(; i<=l; i++)
        {
            if(isalpha(str[i]) || str[i]=='-')
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

