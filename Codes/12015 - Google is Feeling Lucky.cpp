#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
class list
{
public:
    char ulr[120];
    int rate;
};
list ara[20];
bool comp(list a, list b)
{
    if(a.rate!=b.rate) return a.rate>b.rate;
    return a.ulr>b.ulr;
}
int main()
{

#ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
#endif

    int test;
    int value;
    int cas=1;
    char name[120];
    scanf("%d",&test);
    while(test--)
    {
        int i = 10;
        getchar();
        for(i=0; i<10; i++)
        {
            scanf(" %s %d",ara[i].ulr,&ara[i].rate);

        }
        printf("Case #%d:\n",cas++);
        stable_sort(ara,ara+i,comp);
        int m = ara[0].rate;
        i = 0;
        while(ara[i].rate==m)
        {
            printf("%s\n",ara[i].ulr);
            i++;
        }

    }
    return 0;

}

