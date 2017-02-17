#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;
int main()
{
    string course;
    map<string ,int > sparrow;
    int din;
    int num;
    int d;
    int test;
    int koita;
    scanf("%d ",&test);
    for(int cas=1; cas<=test; cas++)
    {
        scanf("%d ",&koita);
        for(int i = 0; i<koita; i++)
        {
            cin>>course;
            scanf("%d ",&din);
            sparrow[course]=din;
        }
        scanf("%d ",&d);
        cin>>course;
        if(sparrow.count(course))
        {
            if(sparrow[course]<=d)
            {
                printf("Case %d: Yesss\n",cas);
            }
            else if(sparrow[course]>d && sparrow[course] <=(d+5)){
                printf("Case %d: Late\n",cas);
            }
            else printf("Case %d: Do your own homework!\n",cas);
            sparrow.clear();
        }
        else {
                printf("Case %d: Do your own homework!\n",cas);
                sparrow.clear();
        }
    }
    return 0;
}
