/*#include <cstdio>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;

#define sz(a) int((a).size())

typedef long long llong;

const int MAXN = 1000256;
bool prime[MAXN];
vector<int> P;

void preprocess()
{
    for(int i = 0; i < MAXN; ++i)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i < MAXN; ++i)
    {
        if(prime[i])
        {
            P.push_back(i);
            for(int j = i + i; j < MAXN; j+=i)
                prime[j] = false;
        }
    }

    swap(P[1], P[2]);
}

int main(int argc, char *argv[])
{
    preprocess();
    int n, res, c2, c5;
    while(1 == scanf("%d",&n))
    {
        if(!n) break;
        res = 1;
        c2 = c5 = 0;
        for(int i = 2; i <= n; i*=2) c2++;
        for(int i = 5; i <= n; i*=5) c5++;
        for(int i = 0; i < c2-c5; ++i) res = (res * 2) % 10;
       cout<<res<<endl;
        for(int i = 2; i < sz(P); ++i)
        {
            if(P[i] > n) break;
            for(llong j = P[i]; j <= n; j*=P[i])
               // cout<<P[i]<<endl;;
                res = (res * P[i]) % 10;
        }

        printf("%d\n",res);
    }
    return 0;
}
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 999985

bool flag[MAX];
vector<int> prime;
void sieve()
{
    int i,j,k,add;
    prime.push_back(2);
    for(int i = 4;i<MAX;i+=2) flag[i]=1;
    for(int i = 3;i<MAX;i+=2){
        if(!flag[i]){
            prime.push_back(i);
            if(MAX/i>=i){
                add = i*2;
                for(j = i*i;j<MAX;j+=add)
                    flag[j]=1;
            }
        }
    }
    swap(prime[1],prime[2]);
}


int main()
{

    int n;
    sieve();
   // for(int i = 0;i<100;i++) cout<<' '<<prime[i];
    int i,j,k,l;
    while(scanf("%d",&n)==1  && n){
        int a22=0,a55=0;
        int lcm=1;
        for(i=2;i<=n;i*=2) a22++;
        for(i = 5;i<=n;i*=5) a55++;
        for(i=0;i<a22-a55;i++) lcm = (lcm*2) %10;
       // cout<<lcm<<endl;
        for(i=2;i<prime.size();i++){
            if(prime[i]>n) break;
            for(long long j = prime[i];j<=n;j*=prime[i]){
                    lcm = (lcm*prime[i])%10;
                    //cout<<prime[i]<<endl;
            }
        }
        //cout<<prime[i];
        printf("%d\n",lcm);
    }
    return 0;

}


