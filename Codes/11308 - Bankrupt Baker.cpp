#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cctype>
using namespace std;
typedef struct
{
    string name;
    int cost;
} cake;
cake ara[105];
bool comp(cake a,cake b)
{
    if(a.cost!=b.cost) return  a.cost<b.cost;
    return a.name < b.name;
}
int main()
{
    map<string,int> ingredient;
    map<string,int> mrec;
    int m,n,b;
    int c;
    int k,x;
    int test;
    string ingrd;
    string requirement;
    string binder;
    string recipes[105];

    scanf("%d\n",&test);
    while(test--)
    {
        getline(cin,binder);
        int sz=binder.size();
        for(int i = 0;i<sz;i++){
            binder[i]=toupper(binder[i]);
        }

        scanf("%d %d %d",&m,&n,&b);
        for(int i = 0; i<m; i++)
        {
            cin>>ingrd;
            scanf("%d",&c);

            ingredient[ingrd]=c;

        }
        cin.ignore();
        for(int i= 0; i<n; i++)
        {
            getline(cin,recipes[i]);


            scanf("%d",&k);
            for(int j = 0; j<k; j++)
            {
                cin>>ingrd;
                scanf("%d",&x);
                mrec[recipes[i]] +=(ingredient[ingrd]*x);
            }
            cin.ignore();
        }
        int flag = 0;
        int con=0;
        for(map<string ,int> :: iterator it=mrec.begin();
                it!=mrec.end(); it++)
        {
            if(it->second <= b) {
                flag = 1;
                ara[con].name=it->first;
                ara[con].cost=it->second;
                con++;
            }
        }
        stable_sort(ara,ara+con,comp);
        if(flag){
                printf("%s\n",binder.c_str());
          //  cout<<binder<<endl;
            for(int i =0;i<con;i++)
                printf("%s\n",ara[i].name.c_str());
               // cout<<ara[i].name<<endl;
        }
        else {
            printf("%s\n",binder.c_str());
           // cout<<binder<<endl;
        printf("Too expensive!\n");
           // cout<<"Too expensive!\n";
        }
        puts("");
        ingredient.clear();
        mrec.clear();
    }
    return 0;
}
