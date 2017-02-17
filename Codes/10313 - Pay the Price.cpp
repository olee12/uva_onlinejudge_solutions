#include<bits/stdc++.h>
using namespace std;
#define M 301
long long normal[301];
long long ara[301];
void func()
{
   normal[0] = 1;
   for(int i = 1;i<=300;i++)
       for(int j = i;j<=300;j++)
       normal[j]+= normal[j-i];
}
long long cnt(int sum,int mx)
{
   for(int i = 0;i<=sum;i++) ara[i]=0;
   ara[0]=1;
   for(int i = 1;i<=mx;i++)
       for(int j = i;j<=sum;j++)
       ara[j]+=ara[j-i];

   return ara[sum];
}
int main()
{
   func();
   char line[100];
   int l1,l2,n;
   while(gets(line))
   {

       int x = sscanf(line,"%d %d %d",&n,&l1,&l2);
       if(x==1)
       {

           printf("%lld\n",normal[n]);
       }
       else if(x==2)
       {
           printf("%lld\n",cnt(n,l1));
       }
       else if(x==3)
       {
           if(n==0) printf("%d\n",l2-l1 + 1);
           else
           printf("%lld\n",cnt(n,l2)-cnt(n,l1-1));
       }
   }
   return 0;
}
