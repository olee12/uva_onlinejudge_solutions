#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
int main()
{
    string dic;
    map<string,int>mp;
    while(cin>>dic && dic != "#")
    {
      //  cout<<dic<<endl;
        mp[dic]++;

    }
    char  word[100];
    char ch;
    int num=0;
    string s1="";
    map<string,int> mp2=mp;
    getchar();
    while(gets(word))
    {
        if(word[0]=='#') break;
        stringstream ss(word);
        dic="";
        while(ss>>ch) dic+=ch;
        sort(dic.begin(),dic.end());
        //  cout<<dic<<endl;
        mp=mp2;

        do
        {
            s1="";
            for(int i = 0; i<dic.size(); i++)
            {
                s1+=dic[i];
                cout<<s1<<endl;;
                if(mp[s1])
                {
                   // cout<<s1<<endl;
                    num+=(mp[s1]);
                    mp[s1]=0;
                }
            }
        }
        while(next_permutation(dic.begin(),dic.end()));
      /*  mp=mp2;
        s1="";
        for(int i = 0; i<dic.size(); i++)
        {
            s1+=dic[i];
           // cout<<s1<<endl;;
            if(mp[s1])
            {
                mp[s1]=0;
                num++;
            }
        }*/
        cout<<num<<endl;
        num=0;
    }


}

