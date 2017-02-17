#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int f=1,g,h;
    char ch;
    int test;
    int line;
    while(cin>>test)
    {
        getchar();
        for(int i=1,g=0; i<=test; i++)
        {
            cin>>line;
            getchar();
            if(i>1) cout<<endl;
            cout<<"Case "<<i<<":"<<endl;

            g=0;
            while(scanf("%c",&ch))
            {

                if((ch==' '||ch=='\t'))
                {
                    if(f)
                    {
                        cout<<" ";
                        f=0;
                    }

                }
                else
                {
                    cout<<ch;
                    f=1;
                }
                if(ch=='\n') g++;
                if(g==line) break;

            }


        }
    }
    return 0;
}
