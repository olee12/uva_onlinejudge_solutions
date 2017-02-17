#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
    string str;
    int i,len;
    int loop,count;
    int test;
    int l=0;
    char temp[100];
    while(cin>>test)
    {
        for(int j=1; j<=test; j++)
        {

            cin>>str;
            cout<<"Case "<<j<<": ";
            len=str.size();
            l=0;
            for(i=0; i<=len; i++)
            {
                if(isdigit(str[i]))
                {
                    loop=i;
                    while(isdigit(str[i]))
                        temp[l++]=str[i++];
                    temp[l]='\0';
                    count=atoi(temp);
                    while(count--) cout<<str[loop-1];
                    l=0;
                }
            }
            cout<<endl;
        }

    }
    return 0;
}
/*count=str[i]-'0';
           while(count--) cout<<str[i-1];*/
