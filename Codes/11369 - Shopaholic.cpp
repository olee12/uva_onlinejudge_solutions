#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
bool comp(int  a,int b);
int main()
{
    int ara[20005];
    int i,j,k,sum;
    int t,items;
    scanf("%d",&t);
        while(t--){
            scanf("%d",&items);

            for(i=0;i<items;i++){
                scanf("%d",&ara[i]);


            }
            sort(ara,ara+items,comp);

            sum=0;
            for(i=2;i<items;i+=3){

                sum+=ara[i];
            }
            printf("%d\n",sum);


        }

    return 0;
}
bool comp(int  a,int b)
{
    return a>b;
}
