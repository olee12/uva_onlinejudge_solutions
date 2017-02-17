#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
#include<list>
#include<set>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    string str;
    string ara;
    bool flag = true;
    int count,i,j;
    while(cin>>str>>ara)
    {

        for( i=0, j=0,count=0; i<str.size(); i++)
        {
            for(j=0; j<ara.size(); j++)
            {
                if(str[i]==ara[j])
                {
                    i++;
                    count++;

                }
            }
        }
        if(count==str.size()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;

}



