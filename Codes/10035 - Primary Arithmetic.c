#include<stdio.h>
#include <stdlib.h>
int main()
{
     long long int e,f,g;
    int a, b,d,y=0,c,x=0;
    while(scanf("%lld %lld",&e,&f)==2)
    {

        if(e == 0 && f == 0) break;
        if(e<0) e = e*-1;
        if(f<0) f = f*-1;
        if(e<f) g=e,e=f,f=g;

        while(e>0 || f>0)
        {
            c = e-(e/10)*10;

            e/=10;
            d = f-(f/10)*10;

            f/=10;
            a = c+d+y;

            if(a>=10)
            {
                x++;
              y = a/10;

            }
            else y = 0;


        }

        if(x==1) printf("%d carry operation.\n", x);
        else if(x>1) printf("%d carry operations.\n", x);
        else printf("No carry operation.\n");

        x = 0;
        y = 0;



    }
    return 0;
}
