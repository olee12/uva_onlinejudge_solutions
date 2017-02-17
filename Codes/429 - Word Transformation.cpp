#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<sstream>
using namespace std;
map<string,int> visited;
int bfsQ(string start,string to,map<string,vector<string> > graph)
{
    queue<string> Q;
    visited[start]=0;
    Q.push(start);
    string top;
    while(!Q.empty()){
         top=Q.front();
        Q.pop();
        if(top == to) return visited[top];
        int sz = graph[top].size();
        for(int i =0;i<sz;i++){
            if(!visited.count(graph[top][i]))
            {
                visited[graph[top][i]]=visited[top]+1;
                Q.push(graph[top][i]);
            }
        }
    }
  //  return visited[to];
}

int main()
{
    int test;
    int n,i,j,k;
    string word;
    map<string,vector<string> > graph;
    string tmp;
    cin>>test;
    while(test--)
    {
        cin>>word;
        while(word!="*")
        {
            graph[word];
            map<string,vector<string> > :: iterator it;
            for(it = graph.begin(); it!=graph.end(); it++)
            {
                tmp=it->first;
                int tmpsz=tmp.size();
                int dif=0;
                if(tmpsz==word.size())
                {
                    for(i=0; i< tmpsz && dif < 2; i++)
                    {
                        if(tmp[i]!=word[i])
                            dif++;
                    }
                    if(dif==1)
                    {
                        graph[word].push_back(tmp);
                        graph[tmp].push_back(word);
                    }
                }
            }
            cin>>word;
        }

     /*   for(map<string,vector<string> >:: iterator it = graph.begin();it!=graph.end();it++){
            cout<< it->first<<" :";
            int sz = it->second.size();
            for(int j = 0;j< sz;j++){
                cout<<" "<<it->second[j];
            }
            puts("");
        }*/
        cin.ignore();
        string start,to,line;
        while(getline(cin,line),line.size()){
            stringstream ss(line);
            ss>>start>>to;
            visited.clear();
            cout<<start<<' '<<to<<' '<<bfsQ(start,to,graph)<<endl;;

        }
        if(test) puts("");
    }
    return 0;

}
