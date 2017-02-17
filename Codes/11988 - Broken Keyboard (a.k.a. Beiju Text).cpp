/*#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<set>
#include<stack>
using namespace std;
int main()
{
    char str[1000000];
    int i,j,k,l,m,n;
    char ch;

    while(gets(str))
    {
        string text="";
        for(l=0,i=0; str[l]; l++)
        {
            i=0;
            if(str[l]!='['&&str[l]!=']')
            {
                text+=str[l];
            }
            else
            {
                ch=str[l];
               string ara="";
                l++;
                while(isalnum(str[l]))
                {
                    ara+=str[l];

                    l++;
                }
                if(ch=='['){
                ara+=text;
                text=ara;
                }
                else if(ch==']') text+=ara;
                if(!str[l]) break;
                l--;
            }*/
           /* else if(str[l]==']')
            {
              string  ara="";
                l++;
                while(isalnum(str[l])){
                    ara+=str[l];
                    l++;
                }
                text+=ara;
                if(!str[l]) break;
                l--;
            }*/

/*
        }
        cout<<text<<endl;
    }
    return 0;
}*/
/*#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<set>
#include<stack>
using namespace std;
int main()
{
    char str[1000000];
    int i,j,k,l,m,n;

    while(gets(str))
    {
        string text="",ara="";
        for(l=0,i=0; str[l]; l++)
        {
            i=0;

            if(str[l]=='[' &&str[l+1]!='\0')
            {
                ara="";
                l++;
                while(str[l]!='['&&str[l]!=']'&&str[l]!='\0')
                {
                    ara+=str[l];

                    l++;
                }
                ara+=text;
                text=ara;
                if(!str[l]) break;
                l--;



            }
            else if(str[l]==']'&&str[l+1]!='\0')
            {
                ara="";
                l++;
                while(str[l]!='[' && str[l] !=']' && str[l]!='\0'){
                    ara+=str[l];
                    l++;
                }
                text+=ara;
                if(!str[l]) break;
                l--;
            }
            else if(str[l]!='['&&str[l]!=']')
            {
                text+=str[l];
            }
        }
        cout<<text<<endl;



    }
    return 0;
}
*/


#include<string.h>
#include<stdio.h>
#define MAXN 100002
char s[MAXN],temp[MAXN];
int main()
{
    int i,len;
    while(~scanf("%s",s))
    {

        len=strlen(s);
        for(i = 0; i < len; ++i)
        {
            if(s[i]=='['||s[i]==']')
                temp[i] = '\0';
            else
               temp[i] = s[i];
        }
        temp[len]='\0';
        for(i = len - 1; i > -1; --i)
        {
            if(s[i]=='[')
                printf("%s",temp+i+1);
        }
        if(!(s[0]=='['||s[0]==']'))
            printf("%s",temp);
        for(i = 1; i < len; ++i){
            if(s[i]==']')
                printf("%s",temp+i+1);
        }
        printf("\n");
    }
    return 0;
}
