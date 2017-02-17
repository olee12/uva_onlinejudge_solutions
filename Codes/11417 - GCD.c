#include<stdio.h>
int main()
{
    int n;
    register i,j,g=0,a,b,t;
    while(scanf("%d",&n)==1)
    {
        for(i=1; i<n; i++)
            for(j=i+1; j<=n; j++)
            {
                a=i,b=j;
                while(a!=0)
                {
                    t=a;
                    a=(b%a);
                    b=t;
                }
                g+=b;
            }
        printf("%d\n",g);
        g=0;

    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int g = 0;
    while(scanf("%d",&n)==1 && n){
        for(int i = 1;i<n;i++){
            for(int j = 1+i;j<=n;j++){
                g+=__gcd(i,j);
            }
        }
        printf("%d\n",g);
        g=0;
    }
    return 0;
}

*/
//int gcd(register int i,register j)
//{
//    register int t;
//    while(a!=0)
//    {
//        t=a;
//        a=(b%a);
//        b=t;
//    }
//    return b;
//}
