#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
 #include<iostream>
        #include<math.h>
using namespace std;
int main()
{
    int n;
    int i;
    ;
    int m;
    while(scanf("%d",&n) && n)
    {

        for(i = 1; i<=n; i<<=1);

        cout<<log2((double)n)<<endl;
        cout<<i<<endl;
        m = i%n;
        printf("%d\n",n-m);
    }
    return 0;
}
