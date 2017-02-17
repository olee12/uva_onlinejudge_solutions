/* wrong code c++:

#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    char imput[100];
    string output;
    string temp="";
    int t;
    while(cin>>t)
    {
        for(int i=1; i<=t; i++)
        {
            fflush(stdin);
            gets(imput);
            fflush(stdin);
            cin>>output;
            fflush(stdin);
            int l=strlen(imput);
            if(l==output.size())
            {
                for(int j=0; j<strlen(imput); j++)
                {
                    temp+=imput[j];
                }

                if(temp==output) cout<<"Case "<<i<<": Yes\n";

                 else cout<<"Case "<<i<<": Wrong Answer\n";
                 temp="";
            }
            else if(l!=output.size())
            {
                for(int j=0; j<l; j++)
                {
                    if(!isspace(imput[j]))
                        temp+=imput[j];
                }
                if(temp==output) cout<<"Case "<<i<<": Output Format Error\n";
                temp="";
            }

        }
    }
    return 0;
}
*/

#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char input[50];
    char output[50];
    char temp[50];
    int test;
    int j,k,l;
    scanf("%d",&test);
    getchar();
    for(int i=1;i<=test;i++){
        gets(input);
        gets(output);
        if(!strcmp(input,output)) printf("Case %d: Yes\n",i);
        else {
                l=strlen(input);
                for(j=0,k=0;j<l;j++){
                    if(!isspace(input[j])){
                        temp[k++]=input[j];
                    }
                }

                temp[k]='\0';

        if(!strcmp(temp,output)) printf("Case %d: Output Format Error\n",i);
        else printf("Case %d: Wrong Answer\n",i);
        }
    }
    return 0;

}
