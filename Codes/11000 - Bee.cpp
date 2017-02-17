#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long lim = (long long)pow(2.00,32);
long long int sum[100];
long long int fib0[100];

void fib()
{
    fib0[0]=0LL;
fib0[1]=1LL;
fib0[2]=1LL;
sum[0]=0LL;
sum[1]=1LL;
sum[2]=2LL;
    long long int i,j,k;
    for(i=3;sum[i-1]<lim;i++){
        fib0[i]=fib0[i-1]+fib0[i-2];
        sum[i]=sum[i-1]+fib0[i];
    }
}
int main()
{
    fib();
    int n;
    while(cin>>n&& n>=0){
        cout<<sum[n]<<" "<<sum[n+1]<<endl;

    }
    return 0;
}
