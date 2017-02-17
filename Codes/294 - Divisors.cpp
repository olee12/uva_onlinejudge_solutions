#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
int main()
{
  long long low , up, t,i,j, divs,maxi,num;
    int a;
    scanf("%lld",&t);

        while(t--)
        {
            maxi=0;
            scanf("%lld %lld",&low,&up);

     if(low==1&&up==0)
     {
          printf("Between 1 and 1, 0 has a maximum of 2 divisors.\n");
          continue;
     }
            for(i=low;i<=up;i++){
                int p = sqrt(i);
                divs=0;
                for(j=1;j<=p;j++){
                    if(i%j==0){
                        divs++;
                        if(i/j != j) divs++;
                    }
                }
                if(maxi<divs){
                    maxi = divs;
                    num = i;
                }
            }
            printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",low,up,num,maxi);
        }

    return 0;
}
