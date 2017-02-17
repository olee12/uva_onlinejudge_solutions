#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
int main()
{
    char ch;
    char ara[12]="OIZEASGTBP";
    int i,k,l;
    int t;
    char text[200];
    scanf("%d\n",&t);
    while(t--)
    {

        while(gets(text))
        {
            for(l =0; text[l]; l++);

            if(!l)
            {
                break;

            }
            for(i=0; i<l; i++)
            {
                if(text[i]>='0'&&text[i]<='9')
                    text[i]=ara[text[i]-'0'];
            }
            printf("%s\n",text);
        }
        if(t)
        {
            printf("\n");
        }
    }

    return 0;
}
