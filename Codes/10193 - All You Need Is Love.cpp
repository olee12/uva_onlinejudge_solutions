#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main()
{
    int a=0;
    int b=0;
   string st1;
   string st2;
   int i,cas=1,j;
    int test;
    scanf("%d",&test);
   while(test--){
        cin>>st1>>st2;
         j = 0;
    for(i=st1.length()-1;i>=0;i--){
        if(st1[i]=='1'){
            a |= (1<<j);

        }
        j++;
    }

    j=0;
    for(i=st2.length()-1;i>=0;i--){
        if(st2[i]=='1'){
            b |= (1<<j);

        }
        j++;
    }
    if(GCD(a,b)>1) printf("Pair #%d: All you need is love!\n",cas++);
    else printf("Pair #%d: Love is not all you need!\n",cas++);
    a=0;
    b=0;

   }
   return 0;

}
