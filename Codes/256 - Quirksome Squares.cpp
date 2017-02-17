#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
int n;
int n1,n2,num[8];
char ara2[3][3]={"00",
"01",
"81"};
char ara4[5][5]={"0000",
"0001",
"2025",
"3025",
"9801"};
char ara6[5][7]={"000000",
"000001",
"088209",
"494209",
"998001"};
char ara8[9][9]={"00000000",
"00000001",
"04941729",
"07441984",
"24502500",
"25502500",
"52881984",
"60481729",
"99980001"};
int seperate(int j)
{
    int p=n-1;
    int l=j;
    for(int i=0;i<8;i++)
        num[i] = 0;
    n1=n2=0;
    int k;
    while(j){
        num[p--] = j%10;
        j/=10;
    }
    int pw=1;
    for(k = n-1;k>=n/2;k--){
        n1=n1+num[k]*pw;
        pw*=10;
    }
    pw=1;
    for(;k>=0;k--){

        n2=n2+num[k]*pw;
        pw*=10;
    }

}
void genate()
{
    int p = n-1;
    int i,k;
    int limit=(int )pow(10,n);
    for(i=0;i<limit;i++){
        seperate(i);
        int sum = (n1+n2)*(n1+n2);
        if(sum == i){
            for(k=0;k<n;k++){
                cout<<num[k];
            }
            cout<<endl;
        }
    }
}
int main()
{



    int i;
    while(cin>>n){
        if(n==2){
            for(i=0;i<3;i++) cout<<ara2[i]<<endl;
        }
        if(n==4){
            for(i=0;i<5;i++) cout<<ara4[i]<<endl;
        }
        if(n==6){
            for(i=0;i<5;i++) cout<<ara6[i]<<endl;
        }
        if(n==8){
            for(i=0;i<9;i++) cout<<ara8[i]<<endl;
        }
    }
    return 0;

}
