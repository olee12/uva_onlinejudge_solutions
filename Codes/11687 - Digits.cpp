#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
#define M 1000050
char str[M];
int main()
{
    int a,b;
    int i;
    char ara[50];
    while(scanf("%s",str))
    {
        if(*str=='E') break;
        if(strcmp("1",str)==0) {
            printf("1\n");
            continue;
        }
        i = 1;
        a = strlen(str);
        b = -1;
        // a = b;
        while(1)
        {

            b = log10(a)+1;
            i++;
            if(a==b) break;

            a = b;
        }
        cout<<i<<endl;
    }
    return 0;
}









