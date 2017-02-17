#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long int i,j,c;
int cube(int n);
int main()
{
    long long  int i,j,l;
    int f,n,s;
    long long c;
    while(cin>>n && n)
    {
        if(!cube(n))
            printf("No solution\n");
    }
    return 0;
}
int cube(int n)
{
    long long int i,j,c;
    for(i=2; i<n; i++)
    {
        c=i*i*i;
        for(j=0; j<i; j++)
        {
            if(n==(c-(j*j*j)))
            {
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }

    }
    return false;
}
