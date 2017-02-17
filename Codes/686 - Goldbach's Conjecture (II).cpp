#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define MAX 40000
bool flag[MAX+2];
vector < int > prime;
void sieve()
{
     flag[0]=1;
flag[1]=1;
flag[2]=0;
    int i,j,k;
    prime.push_back(2);
    for(i=4;i<=MAX;i+=2)
        flag[i]=1;
    for(i=3;i<=MAX;i+=2){
        if(!flag[i]){
            prime.push_back(i);
            if(MAX/i>i){
            k=i*2;
            for(j=i*i;j<=MAX;j+=k){
                flag[j]=1;
            }
            }

        }
    }
}

int main()
{
    sieve();

    int a,b,i,num,count=0;
    while(scanf("%d",&num) && num){
        for(i=0;num>=prime[i];i++){
            b=num-prime[i];
            if(!flag[b] && b>=prime[i]){
              count++;
            }
        }
        printf("%d\n",count);
        count=0;
    }
return 0;
}
