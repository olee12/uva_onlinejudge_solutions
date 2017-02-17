#include<cstdio>
#include<cstring>
#include<iterator>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
using namespace std;
map<char,double> mask;
int main()
{
    //freopen("input.txt","r",stdin);
    char str[1000005];
    mask['W'] = 1.;
    mask['H'] = 1./2.;
    mask['Q'] = 1./4.;
    mask['E'] = 1./8.;
    mask['S'] = 1./16.;
    mask['T'] = 1./32.;
    mask['X'] = 1./64.;
    int cnt = 0;
    double n;
    char *p;
    while(gets(str))
    {

        if(strcmp(str,"*")==0) return 0;
        cnt = 0;
        p = strtok(str,"/");
        while(p!=NULL)
        {
                n = 0;
            for(int i = 0; p[i]>='A' && p[i]<='Z'; i++)
            {
                n+= mask[p[i]];
             //   printf("%c\n",*p);
            }
            if(fabs(n-1) < 1e-11) cnt++;
            p = strtok(NULL,"/");
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define ERROR 1e-11
using namespace std;

char input[1000000];
int main()
{
    freopen("input.txt","r",stdin);
    int counter, i;
    double sum;
    char *p;
    while (gets(input))
    {
        if (!strcmp(input,"*")) break;


        counter=0;
        p = strtok(input,"/");
        printf("%c\n",*p);
        while (p!=NULL)
        {
            for (i=0, sum=0 ; p[i]>='A'&&p[i]<='Z' ; i++)
            {
                if (p[i]=='W') sum += 1.0;
                else if (p[i]=='H') sum += 1.0/2.0;
                else if (p[i]=='Q') sum += 1.0/4.0;
                else if (p[i]=='E') sum += 1.0/8.0;
                else if (p[i]=='S') sum += 1.0/16.0;
                else if (p[i]=='T') sum += 1.0/32.0;
                else if (p[i]=='X') sum += 1.0/64.0;
            }
            if (fabs(sum-1)<ERROR) counter++;

            p = strtok(NULL,"/");
            if(p!=NULL) printf("%c\n",*p);

        }
        printf("%d\n",counter);
    }
    return 0;
}
*/
