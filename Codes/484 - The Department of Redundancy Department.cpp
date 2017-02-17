#include<iostream>
#include<cstdio>
#include<map>
#include<iterator>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
    map<long long ,long long > mp;
    vector<long long> imput;
    long long a,b;
    while(scanf("%lld",&a)==1){
            if(!mp[a])
                imput.push_back(a);
        mp[a]++;
    }
    for(unsigned long long i = 0;i<imput.size();i++){
        printf("%lld %lld\n",imput[i],mp[imput[i]]);
    }

    return 0;
}
