/*#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    int n;
    vector<int> v;
    while(scanf("%d",&n)==1){
        v.push_back(n);
        sort(v.begin(),v.end());
        if( !(v.size()%2)) printf("%d\n",(v[v.size()/2]+v[v.size()/2 -1])/2);
        else printf("%d\n",v[v.size()/2]);
    }
    return 0;
}
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
vector<int> list;

/*int main()
{
    while(scanf("%d", &n) == 1)
    {
        list.push_back(n);
        for(int i = 0; i < list.size(); i++)
            if(list[i] > n) swap(list[i], list[list.size() - 1]);
        if(list.size() % 2 == 0)
        {
            printf("%d\n", (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2);
        }
        else printf("%d\n", list[list.size() / 2]);
    }
    return 0;
}
*/
int main()
{
    while(scanf("%d",&n)==1){
        list.push_back(n);
        for(int i =0;i<list.size();i++){
            if(list[i] > n) swap(list[i],list[list.size()-1]);

        }
          if(list.size() % 2 == 0)
        {
            printf("%d\n", (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2);
        }
        else printf("%d\n", list[list.size() / 2]);
    }
    return 0;
}
