#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 1000001
bool ara[MAX];
int main()
{

   register int i,j,k,l,m,num;
    for(i=1; i<MAX; i++)
    {
        num=i;
        l=num;
        k=0;
        while(l){
            k+=l%10;
            l/=10;
        }
        num+=k;
        //cout<<num<<endl<<endl;
        while(num<MAX)
        {
            if(ara[num]) break;
            ara[num]=1;
            //cout<<num<<endl;
            l=num;
            m=0;
            while(l!=0)
            {
                m+=(l%10);
                l/=10;
            }
            num+=m;
        }
    }
    for( i =1;i<MAX;i++) if(!ara[i]) cout<<i<<endl;
    return 0;
}
