/*#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string str;
    int test;
    cin>>test;
    {
        for(int i=1; i<=test; i++)
        {
            cin>>str;
            if(str.length()==2)
            {
                printf("Case %d: %g\n",i,.5*(str[0]-'0'));
            }
            else if(str.length()==3)
            {
                int a,b;
                a=str[0]-'0';
                a*=10;
                b=str[1]-'0';
                a+=b;
                printf("Case %d: %g\n",i,.5*a);
            }
            else
            {
                if(str.length()==4)
                    printf("Case %d: %g\n",i,.05*(str[2]-'0')+.5*(str[0]-'0'));
                else
                {
                    int a,b;
                    a=str[0]-'0';
                    a*=10;
                    b=str[1]-'0';
                    a+=b;
                    printf("Case %d: %g\n",i,.05*(str[3]-'0')+.5*a);
                }
            }
        }
    }
    return 0;

}*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int a,b,test;
    string str;

    cin>>test;
    for(int i=1; i<=test; i++)
    {
        cin>>a>>str;
        b = str.length() > 3 ?(int ) str[3] - '0' : 0;
        cout<<"Case "<<i<<": "<<a*0.5+b*0.05<<endl;
    }
    return 0;

}
