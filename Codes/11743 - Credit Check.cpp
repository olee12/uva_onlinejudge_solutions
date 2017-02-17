#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int sum_for;
    int sum_bck;
    char str[100];
    int test;
    scanf("%d ",&test);

    while(test--)
    {
        sum_for = 0;
        sum_bck = 0;
        int tmp=0;
        gets(str);
        int j =strlen(str);
        for(int i = 0; i<j; i+=2)
        {
            if(str[i]==' ') i++;
            tmp  = (str[i]-'0');
            tmp*=2;
            while(tmp!=0)
            {
                sum_for+=(tmp%10);
                tmp/=10;
            }
           // cout<<tmp<<' ';
        }

      //  cout<<endl;
        for(int i = j-1; i>=0; i-=2)
        {
            if(str[i]==' ') i--;
            sum_bck+=(str[i]-'0');
            // sum_for+=(str[i-1]-48);
           // cout<<str[i]<<' ';
        }
       // cout<<endl;
        sum_for+=sum_bck;
       // cout<<sum_for<<endl;
        if((sum_for%10)==0) printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}
