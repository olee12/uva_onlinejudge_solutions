#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include<sstream>

using namespace std;
int main()
{
    string eng,forg,a,b;
    map<string,string> mp;
    int i,j,k,l1,l2;
    while(getline(cin,a),a.size())
    {
        stringstream ss;
        ss<<a;
        ss>>eng>>forg;
        mp[forg]=eng;
    }
    while(cin>>b)
    {
        cout<<(mp.count(b)? mp[b]:"eh")<<endl;
    }
    return 0;
}
