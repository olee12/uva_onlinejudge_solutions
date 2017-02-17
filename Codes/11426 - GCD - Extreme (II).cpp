#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iterator>
#include<cmath>
using namespace std;
#define M 4000005
typedef long long ll;
ll phi[M],ans[M],f[M];

void phi_phi_phi()
{
    for(int i = 0; i<M; i++) phi[i]=i;
    for(int i = 2; i<M; i++)
    {
        if(phi[i]==i)
        {
            for(int j = i; j<M; j+=i)
            {
                phi[j] -= phi[j]/i;
            }
        }
    }
    //cout<<phi[400000]<<endl;
    /*
    explanation of my code .. karo jodi bujte kono somossa hoy , tahole amar shate contact koro ...

    build table
    if input is 6 , then we can make this table :
    1 2       1 3         1 4     1 5     1 6
              2 3         2 4     2 5     2 6
                          3 4     3 5     3 6
                                  4 5     4 6
                                          5 6
    this table is came this given loop;
    for(i=1;i<N;i++)
        for(j=i+1;j<=N;j++)
        {
            G+=gcd(i,j);
        }

    look at the table , we can define a function , f(n) = gcd(1,n)+gcd(2,n)+gcd(3,n) + ... + gcd(n-1,m); .........(1);
    Now we are looking for the sum;
    let define another function cass ans(n) = f(2)+f(3)+...+f(n); ..........(2); (n>2)
    look , we can make this more simple , ans(n) = ans(n-1)+f(n); ..........(3)

    if gcd(a,n) == b, then gcd(a/b,n/b)==1 ;
        for example ,
    gcd(2,10)=gcd(6,10)=gcd(4,10)=gcd(8,10)==2 and so gcd(2/2,10/2)=gcd(6/2,10/2)=gcd(4/2,10/2)=gcd(8/2,10/2)==1;..........(4)

    now look we can replace f(n) with , b ( b == each divisor of n) * phi(n/b) ;.......(5);  (baucase of (4) );
   // if you want to know what is phi() function , please visite : http://progkriya.org/gyan/basic-number-theory.html ;

    so finaly our function  is , ans(n) = ans(n-1)+ (b * phi(n/b) );..........(6) where b == each divisor of n;
    */
    for(int i = 1; i<M; i++)
        for(int j = i*2; j<M; j+=i)
            f[j]+= i*(phi[j/i]);

    ans[2]=f[2];
    // cout<<f[4]<<endl;
    //cout<<f[6]<<endl;
    //cout<<f[10]<<endl;
    //cout<<f[15]<<endl;
    for(int i = 3; i<M; i++)
    {
        ans[i] = ans[i-1]+f[i];
    }
}
int main()
{
    phi_phi_phi();
    int n;

    while(scanf("%d",&n),n)
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
