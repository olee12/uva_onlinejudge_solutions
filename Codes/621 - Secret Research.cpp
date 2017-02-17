#include<bits/stdc++.h>
using namespace std;
int main()
{
    //string str;
    char str[100];
    int test;
    scanf("%d",&test);
    getchar();
    // cin.ignore();
    while(test--)
    {

        scanf(" %s",str);
        if(!strcmp(str,"1") || !strcmp(str,"4") || !strcmp(str,"78") )
        {
            printf("+\n");
            continue;
        }
        int len = strlen(str);
        if(len>2 && str[len-1]=='5' && str[len-2]=='3')
        {
            printf("-\n");
        }
        else if(len>2 && str[0]=='9' && str[len-1]=='4') printf("*\n");
        else if(len>2 && str[0]=='1'&&str[1]=='9'&&str[2]=='0') printf("?\n");
    }
    return 0;
}
