#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long income;
    int long long pay,b,c;
    int ara[5]= {180000,300000,400000,300000};
    double tax[5]= {0,10,15,20,25};
    int ara2[]={30000,60000,60000};
    int count,j,i;
    scanf("%d",&count);

        for(i=1; i<=count; i++)
        {
            pay=b=c=0;
            scanf("%lld",&income);
            if(income<=ara[0])
            {
                printf("Case %d: 0\n",i);
                continue;
            }
            else
            {
                income-=ara[0];
                    for(j=1; income-ara[j]>0 && j<4; j++)
                    {

                        income-=ara[j];
                            pay+=ara2[j-1];

                    }
                    if(income>0)
                        {

                            pay+=ceil(income*tax[j]/100.0);

                        }
            }
            if(pay<2000) pay=2000;
            printf("Case %d: %lld\n",i,pay);

        }

    return 0;
}
