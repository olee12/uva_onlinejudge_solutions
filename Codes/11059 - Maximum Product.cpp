#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;
int main()
{
    int test;
    int c=1;

    long long  MAxi;

    long long flag;

    long long  ara[22];

    while(cin>>test)
    {

        for(int i=0; i<test; i++) cin>>ara[i];
        MAxi=0;
        for(int i=0; i<test; i++)
        {
          flag = 1;
            for(int j=i; j<test; j++)
            {
                flag*=ara[j];

                if(flag>MAxi) MAxi=flag;
            }

        }
        printf("Case #%d: The maximum product is %lld.\n\n",c++,MAxi);
    }
    return 0;
}
