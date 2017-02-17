#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
struct order
{
    string str;
    int n;
};
bool comp(order x,order y)
{
    if(x.str<y.str){
        return 1;
    }
    return 0;
}
int main()
{
    int test;
    string country;
    string name;
    while(cin>>test){
            map<string , int >mp;
            order k[1005];
        while(test--){

            cin>>country;
            getline(cin,name);
            mp[country]++;

        }
    map<string,int>::iterator it;
    int i=0;
    for(it=mp.begin();it!=mp.end();it++){
        string st=it->first;
        int d=it->second;
        k[i].str=st;
        k[i].n=d;
        i++;
    }
    int p=i;
    sort(k,k+p,comp);
    for(int i=0;i<p;i++){
        cout<<k[i].str<<" "<<k[i].n<<endl;
    }
    }
}
