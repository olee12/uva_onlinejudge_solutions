//accept
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
bool is_valid(string str,int from)
{
    int eq = 0;
    for(int i = 0; i<str.size(); i++)
    {
        if(isdigit(str[i])) eq = str[i] - 48;
        else eq = str[i]-55;
        if(eq<0 || eq>= from) return false;
    }
    return true;
}
long long power(int i,int j)
{
    long long num=1;
    for(int k = 1; k<=j; k++)
    {
        num*=i;
    }
    return num;
}
long long tenbase(string str, int from)
{
    long long val=0;
    int eq;
    int len = str.size();
    for(int i = len -1; i>=0; i--)
    {

        if(isdigit(str[i])) eq = str[i]-48;
        else eq = str[i]-55;
        val += (eq* power(from,len-1-i));
    }
    return val;
}
string base_change(long long a,int to)
{
    string res="";
    int j;
    while(a)
    {
        j = a%to;
        res += ( (j>=10)? j+55 : j+48);
        a/=to;
    }
    if(res.size()==0) res+="0";
    // string :: iterator it = res
    reverse(res.begin(),res.end());
    return res;

}
int main()
{
    #ifndef ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int from,to;
    char ara[20];
    while(scanf("%d %d %s",&from,&to,ara)==3)
    {
        string str(ara);
        if(is_valid(str,from))
        {

            long long ten = tenbase(str,from);
            printf("%s base %d = %s base %d\n",ara,from,base_change(ten,to).c_str(),to);
           // cout<<str<<" base "<<from" = "<<base_change(ten,to)<<" base "<<to<<endl;

        }
        else {
            printf("%s is an illegal base %d number\n",ara,from);
        }

    }
    return 0;

}

//bap re bap
/*
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
bool is_valid(string str,int from)
{
    int eq = 0;
    for(int i = 0; i<str.size(); i++)
    {
        if(isdigit(str[i])) eq = str[i] - 48;
        else eq = str[i]-55;
        if(eq<0 || eq>= from) return false;
    }
    return true;
}
long long power(int i,int j)
{
    long long num=1;
    for(int k = 1; k<=j; k++)
    {
        num*=i;
    }
    return num;
}
long long tenbase(string str, int from)
{
    long long val=0;
    int eq;
    int len = str.size();
    for(int i = len -1; i>=0; i--)
    {

        if(isdigit(str[i])) eq = str[i]-48;
        else eq = str[i]-55;
        val += (eq* power(from,len-1-i));
    }
    return val;
}
string base_change(long long a,int to)
{
    string res="";
    int j;
    while(a)
    {
        j = a%to;
        res += ( (j>=10)? j+55 : j+48);
        a/=to;
    }
    if(res.size()==0) res+="0";
    // string :: iterator it = res
    reverse(res.begin(),res.end());
    return res;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int from,to;
    char ara[20];
    while(scanf("%d %d %s",&from,&to,ara)==3)
    {
        string str(ara);
        if(is_valid(str,from))
        {

            long long ten = tenbase(str,from);
            printf("%s base %d = %s base %d\n",ara,from,base_change(ten,to).c_str(),to);
           // cout<<str<<" base "<<from" = "<<base_change(ten,to)<<" base "<<to<<endl;

        }
        else {
            printf("%s is an illegal base %d number\n",ara,from);
        }

    }
    return 0;

}
*/
