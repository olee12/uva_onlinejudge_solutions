/*#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int n;
    int way;
    int i,j,k,l,m;
    int a,b,c,d,e;

    while(scanf("%d",&n)){
            way=0;

        if(n<5) printf("There is only 1 way to produce  %d cents change.\n",n);
        else{
                b=n/5;
                c=n/10;d=n/25;
                e=n/50;

                for(i=0;i<=n;i++){
                    for(j=0;j<=b;j++){
                        for(k=0;k<=c;k++){
                            for(l=0;l<=d;l++){
                                for(m=0;m<=e;m++){

                                    if((i*1+5*j+10*k+25*l+50*m)==n)
                                                    way++;
                                }
                            }
                        }
                    }
                }
            printf("There is only %d ways to produce  %d cents change.\n",way,n);
        }
    }
    return 0;
}*/

#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
#define MAX 30000
long long nway[MAX+2];
int coin[5]= {50,25,10,5,1};
int main()
{
    int i,j,n,v,c;

    v=5;
    nway[0]=1;
    for(i=0; i<v; i++)
    {
        c = coin[i];
        for(j=c; j<=MAX; j++)
        {
            nway[j] +=nway[j-c];
        }
    }

    while(scanf("%d",&n)==1)
    {
    if(nway[n]==1)
            printf("There is only %lld way to produce %d cents change.\n",nway[n],n);
        else
            printf("There are %lld ways to produce %d cents change.\n",nway[n],n);
    }
    return 0;
}
