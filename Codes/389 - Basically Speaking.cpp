#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long power(int i,int j)
{
    ll val=1;
    for(int k=1;k<=j;k++) val*=i;
    return val;
}
bool is_valid(string str,int from)
{
    int eq;
    int len = str.size();
    for(int i = len-1;i>=0;i--){
        if(isdigit(str[i])) eq = str[i]-48;
        else eq = str[i]-55;
        if(eq<0 || eq>=from) return false;
    }
    return true;
}
ll tenbase(string str,int from)
{
    ll val= 0;
    int eq;
    int len  = str.size();
    for(int i = len-1;i>=0;i--){
        if(isdigit(str[i])) eq = str[i]-48;
        else eq = str[i]-55;
        val += (eq * power(from,len-1-i));
    }
    return val;
}
string newbase(ll n,int to)
{
    string str="";
    int j = 0;
    while(n){
         j =n%to;
         str+=( (j>=10)?j+55:j+48   );
         n/=to;
    }
    if(str.size()==0) str+="0";
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char str[100];
    int to,from;
    while(scanf("%s %d %d",str,&from,&to)==3){
        if(is_valid(str,from)){
            ll res = tenbase(str,from);
            string fin = newbase(res,to);
            if(fin.size()<=7) printf("%7s\n",fin.c_str());
            else printf("%7s\n","ERROR");
        }
        else printf("%7s\n","ERROR");
    }
    return 0;
}
