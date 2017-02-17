#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{


    int l,n;
    int f,i,j,k,len;
    string str;
    string name[21][21];
    while(cin>>l>>n)
    {

        for(int i=0; i<l; i++)
        {
            cin>>name[i][0]>>name[i][1];
        }

        for(i=0; i<n; i++)
        {
            cin>>str;
            f=0;
            for(j=0; j<l; j++)
            {
                if(str==name[j][0])
                {
                    f=1;
                    cout<<name[j][1]<<endl;;
                    break;
                }
            }
            if(f)
            {

                continue;
            }
            len=str.length();
            if(str[len-1]=='y'&&str[len-2]!='a'&&str[len-2]!='e'&&str[len-2]!='i'&&str[len-2]!='o'&&str[len-2]!='u')
            {
                str[len-1]='i';
                str+='e';
                str+='s';
            }
            //"o", "s", "ch", "sh" or "x", append "es"
            else if((str[len-1]=='o')||(str[len-1]=='s')||(str[len-2]=='c'&&str[len-1]=='h')||(str[len-2]=='s'&&str[len-1]=='h')||(str[len-1]=='x'))
            {
                str.append("es");

            }
            else str+='s';
            cout<<str<<endl;

        }
    }
    return 0;
}
