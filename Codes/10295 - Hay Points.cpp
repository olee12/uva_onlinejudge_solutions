#include<iostream>
#include<map>
#include<string>
#include<iterator>
#include<sstream>
#include<cstdio>
#include<climits>
using namespace std;
int main()
{
    map<string , double> mp;
    int m,n;
    cin>>m>>n;
    int i,j,k,l;
    string word,paragraph;
    double salary,sum;
    for(i=0;i<m;i++){
        cin>>word>>salary;
        mp[word]=salary;
    }
    while(n--){
            sum=0;
        while(cin>>paragraph && paragraph !="."){
            if(mp.count(paragraph)){
                sum+=mp[paragraph];
            }
        }
        cout<<sum<<endl;
    }
    return 0;

}
