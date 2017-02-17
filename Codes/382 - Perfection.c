#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int a,b;
    int sum=0;
    double t;
    int n=1;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&a)==1 && a)
    {

        sum=0;
       for(b=1;b<=a/2;b++)
        if(!(a%b)) sum+=b;
        if(sum == a) printf("%5d  PERFECT\n",a);
        else if(sum<a) printf("%5d  DEFICIENT\n",a);
        else if(sum>a) printf("%5d  ABUNDANT\n",a);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
