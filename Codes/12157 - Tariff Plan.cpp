#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int test,num,ara[500];
    int i,j,k,milk,jucie;
    scanf("%d",&test);
    for(k=1;k<=test;k++){
            milk=0;jucie=0;
        scanf("%d",&num);
        for(i=0;i<num;i++){ scanf("%d",&ara[i]);
            milk+=(ara[i]/30 +1);
            jucie+=(ara[i]/60 + 1);
            cout<<jucie;

        }
        milk*=10;
        jucie*=15;
        if(milk<jucie)
                printf("Case %d: Mile %d\n",k,milk);
        else if(jucie<milk) printf("Case %d: Juice %d\n",k,jucie);
        else printf("Case %d: Mile Juice %d\n",k,milk);
    }
    return 0;
}
