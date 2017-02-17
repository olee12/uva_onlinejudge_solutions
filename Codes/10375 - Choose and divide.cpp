#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    double p,q,r,s;
    double res;
    int i,j,k,l;
    while(cin>>p>>q>>r>>s)
    {
        res=1;
        if(q>p/2) q=p-q;
        if(s>r/2) s=r-s;
        i=1;
        j=1;

        while(i<=q||j<=s)
        {
            if(i<=q)
            {
                res*=(p-i+1);
                res/=i;
            }
            if(j<=s)
            {
                res*=j;
                res/=(r-j+1);
            }
            i++;
            j++;


        }
        printf("%0.5lf\n",res);
    }
    return 0;
}
