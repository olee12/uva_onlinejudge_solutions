#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    char ch;
    int n,m;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %c %d %d",&ch,&n,&m);
        if(ch == 'Q'||ch=='r') printf("%d\n",min(m,n));
        else if(ch=='k') printf("%d\n",(m*n+1)/2);
        else if(ch=='K') printf("%d\n",((n+1)/2) * ((m+1)/2));
    }
    return 0;
}
