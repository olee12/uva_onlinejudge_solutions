#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main()
{
    char str[100];
    int d;
    while(gets(str)){
            if(atoi(str)<0) break;
        if(str[0]=='0'&&str[1]=='x'){
            //int d=atoi(&str[2]);

            sscanf(&str[2],"%x",&d);
            printf("%d\n",d);
        }
        else printf("0x%X\n",atoi(str));
    }
    return 0;
}
