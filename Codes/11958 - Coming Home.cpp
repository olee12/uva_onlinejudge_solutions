#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int h1,h2,m1,m2;
    int test;
    int k;
    int dis;
    int cas=1;
    int min ;
    int sum1,sum2 ;
    scanf("%d",&test);
    while(test--){
            min = 1e10;
        scanf("%d %d:%d",&k,&h1,&m1);
        sum1 = h1*60+m1;
        for(int i = 0;i<k;i++){

            scanf("%d:%d %d",&h2,&m2,&dis);
            sum2 = h2*60+m2;
            if(sum1>sum2) sum2+=(24*60);

            dis = sum2-sum1+dis;

            if(dis<min) min = dis;
        }
        printf("Case %d: %d\n",cas++,min);
    }
    return 0;

}
