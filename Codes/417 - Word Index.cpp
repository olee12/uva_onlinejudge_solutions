#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string data = "abcdefghijklmnopqrstuvwxyz";

map<string,int> mp;
void creat()
{
    string s,s1,s2,s3,s4,s5;
    int i,j,k,l,m,p=1;
    for(i=0; i<26; i++)
    {
        s=data[i];
        mp[s]=p;
        p++;
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
        {
            s1=data[i];
            s2=data[j];
            s=s1+s2;
            mp[s]=p;
            p++;
        }
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
            for(k=j+1; k<26; k++)
            {
                s1=data[i];
                s2=data[j];
                s3=data[k];
                s=s1+s2+s3;
                mp[s]=p;
                p++;
            }
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
            for(k=j+1; k<26; k++)
                for(l=k+1; l<26; l++)
                {
                    s1=data[i];
                    s2=data[j];
                    s3=data[k];
                    s4=data[l];
                    s=s1+s2+s3+s4;
                    mp[s]=p;
                    p++;
                }
    }
    for(i=0; i<26; i++)
    {
        for(j=i+1; j<26; j++)
            for(k=j+1; k<26; k++)
                for(l=k+1; l<26; l++)
                    for(m=l+1; m<26; m++)
                    {
                        s1=data[i];
                        s2=data[j];
                        s3=data[k];
                        s4=data[l];
                        s5=data[m];
                        s=s1+s2+s3+s4+s5;
                        mp[s]=p;
                        p++;
                    }

    }
}
int main()
{
    creat();
    char str[50];
    while(scanf("%s",str)==1)
    {
        printf("%d\n",mp[str]);
    }
    return 0;

}
