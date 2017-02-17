#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n,d,r;
    int mor[105];
    int eve[105];
    int sm;
    int se;
    while(cin>>n>>d>>r)
    {
        if(n==0&&d==0&&r==0) break;
        for(int i=0; i<n; i++)
        {
            cin>>mor[i];

        }
        for(int i=0; i<n; i++)
        {
            cin>>eve[i];

        }
        int s,f=0,c;
        sort(mor,mor+n);
        sort(eve,eve+n);
        for(int i=0,j=n-1;j>=0;j--,i++){
                c=mor[i]+eve[j];
            if(c>d){
                f+=(c-d)*r;

            }
        }
        cout<<f<<endl;


    }
    return 0;
}
/*  for(int i=0;i<n;i++) cout<<mor[i]<<" ";
        for(int i=0; i<n; i++)
        {

            int j=i+1;
            while(mor[i]<d && j<n)
            {
                if(mor[j]>d)
                {
                    s=d-mor[i];
                    f=0;
                    while(mor[j]>d&&f!=s)
                    {
                        f++;
                        mor[j]--;
                    }

                    mor[i]+=f;



                }
                j++;
            }
        }
        f=0;
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<mor[i]<<" ";
            f+=(mor[i]-d);
        }
        cout<<endl;
        cout<<f*r<<endl;*/
