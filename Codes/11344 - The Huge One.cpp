#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
#include<cctype>
int sv[]= {1,3,2,-1,-3,-2};
bool two(char str[])
{
    int len = strlen(str);
    int a = str[len-1]-'0';
    return (a%2 == 0);
}
bool three(char str[],int n)
{
    int sum = 0;
    int len = strlen(str);
    for(int i = 0; i<len; i++)
        sum+=(str[i]-'0');
    return (sum%n==0);
}
bool four(char str[])
{
    int len = strlen(str);
    if(len < 2) return ( (str[0]-'0')%4 == 0 );
    if((str[len-2]-'0')%2 == 0) return (str[len-1]=='0' || str[len-1]=='4' || str[len-1]=='8');
    if((str[len-2]-'0')%2) return (str[len-1]=='6' || str[len-1]=='2');
}
bool five(char str[])
{
    int len = strlen(str);
    return (str[len-1]=='0' || str[len-1]=='5');
}
bool seven(char str[0])
{
    int len = strlen(str);
    int sum = 0;
    int j=0;
    for(int i = len-1; i>=0; i--)
    {
        sum+= ((str[i]-'0') * sv[j++]);
        if(j==6) j = 0;
    }
    return (sum%7==0);
}
bool eight(char str[])
{
    int len = strlen(str);
    if(len<3) return ((atoi(str)%8)==0);
    if((str[len-3]-'0')%2 == 0) return (atoi(&str[len-2]) % 8 == 0);
    if((str[len-3]-'0')%2) return ((atoi(&str[len-2]) + 4) % 8 == 0);
    return 0;

}
bool eleven(char num[])
{
    int i,j=strlen(num);
    int a=0,b=0;
    for (i=0; i<j; i++ )
    {

        if(i&1)
        {
            b += num[i] - 48;
        }
        else

            a += num[i] - 48;
    }
    b = b*-1;
    if(((a+b)%11)==0) return 1;
    return 0;
}
bool ten(char str[])
{
    int len = strlen(str);
    return (str[len-1]=='0');
}
int main()
{
    // freopen("input.txt","r",stdin);
    char str[1010];
    int test;
    int n,ara[20];
    bool a2,a3,a4;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",str);
        scanf("%d",&n);
        for(int i= 0; i<n; i++) scanf("%d",ara+i);
        bool flag = 1;
        a2 = two(str);
        a3 = three(str,3);
        a4=four(str);
        for(int i = 0; i<n; i++)
        {
            switch(ara[i])
            {
            case 1 :
                break;
            case 2:
                flag&=a2;
                //
                break;
            case 3:
                flag&=a3;

                break;
            case 4:
                flag&=a4;

                break;
            case 5:
                flag&=five(str);
                break;
            case 6:
                flag&=a3;
                flag&=a2;

                break;
            case 7:
                flag&=seven(str);

                break;
            case 8:
                flag&=eight(str);

                break;
            case 9:
                flag&=three(str,9);
                break;
            case 10:
                flag&=ten(str);
                break;
            case 11:
                flag&=eleven(str);
                break;
            case 12:
                flag&=a4;
                flag&=a3;
                break;
            }
        }
        if(flag==1) printf("%s - Wonderful.\n",str);
        else printf("%s - Simple.\n",str);
    }
    return 0;
}

