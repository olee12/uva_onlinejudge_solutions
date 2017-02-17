/*#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector< int > res;
    queue < int > ara;
    int i;
    int num;
    while(cin>>num && num){
            if(num==1)
        {
            cout<<"Discarded cards:\nRemaining card: 1\n";
            continue;
        }

        for(i=1;i<=num;i++){
            ara.push(i);
        }


        while(ara.size()!=2){
            res.push_back(ara.front());
            ara.pop();
            ara.push(ara.front());
            ara.pop();
        }
            res.push_back(ara.front());
            ara.pop();
            printf("Discarded cards:");
            for(i=0;i<res.size()-1;i++)
                printf(" %d,",res[i]);
            printf(" %d\n",res[i]);
        printf("Remaining card: %d\n",ara.front());
        ara.pop();
        res.clear();

    }
    return 0;
}
*/
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    queue < short> ara;
    int i;
    int num;
    while(cin>>num && num){
                 if(num==1)
        {
            cout<<"Discarded cards:\nRemaining card: 1\n";
            continue;
        }
        for(i=1;i<=num;i++){
            ara.push(i);
        }
        printf("Discarded cards:");

        while(ara.size()!=2){
            printf(" %d,",ara.front());
            ara.pop();
            ara.push(ara.front());
            ara.pop();
        }
         printf(" %d\n",ara.front());
            ara.pop();
        printf("Remaining card: %d\n",ara.front());
        ara.pop();

    }
    return 0;
}

