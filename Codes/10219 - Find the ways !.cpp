#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n,r;
    double s;
    int num = 0;
    while(cin>>n>>r)
    {
        s=1;
        if(r> n/2) r = n-r;
        for(int i = 1; i<=r; i++)
        {
            s = s*(n-i+1);
            s/=i;
            //cout<<"s in out: "<<s<<endl;
            if(s>=10)
            {

                while(s>=10)
                {
                    num++;
                    s/=10;
                    // cout<<"s in : ";
                    // cout<<s<<endl;
                }
            }
        }
        int ss=s;

        while(ss!=0)
        {
            num++,ss/=10;
        }

        cout<<num<<endl;
        num=0;
        s=1;
    }
    return 0;
}
