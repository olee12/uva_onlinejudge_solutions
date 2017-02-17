#include<stdio.h>
#include<math.h>
int main()
{
    long long int b,s;
    int cnt=1;
    while(scanf("%lld %lld",&b,&s)==2 && (b+s))
    {
        if(b<=1||s==0) printf("Case %d: :-\\\n",cnt++);
        else if(s>=b) printf("Case %d: :-|\n",cnt++);
        else
        {
            if((s*(b-1))>(b*(s-1))) printf("Case %d: :-(\n",cnt++);
            else printf("Case %d: :-)\n",cnt++);

        }

    }
    return 0;
}
