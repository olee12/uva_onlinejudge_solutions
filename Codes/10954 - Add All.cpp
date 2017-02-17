#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    priority_queue<int > q;
    int num;
    int a;
    int cost,finl;
    vector<int > ara,ara2;
    while(cin>>num && num){

        for(int i=0;i<num;i++){
            cin>>a;
            q.push(a);
        }
        while(!q.empty()){
            ara.push_back(q.top());
            q.pop();

        }
        cost=finl=0;
        for(vector<int>::iterator it=ara.end()-1;it>=ara.begin();it--){
           cost+=*it;
           ara2.push_back(cost);

        }
        for(vector<int>::iterator it=ara2.end()-1;it>=ara2.begin()+1;it--) finl+=*it;
            cout<<finl<<endl;
        ara.clear();
        ara2.clear();

    }
    return 0;
}
