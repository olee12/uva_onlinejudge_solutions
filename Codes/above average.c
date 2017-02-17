#include<stdio.h>
int main()
{
    int n,i,j,k,l,count,m,man[1010],a=0,b,c,d;
    float sum,ave;
    scanf("%d\n", &n);
    for(i=1; i<=n; i++)
    {


        sum = 0;
        count = 0;
        scanf("%d", &j);
        for(k=0; k<j; k++)
        {
            scanf("%d",&man[k]);
            sum += man[k];
        }
        ave = sum/(float)j;
        b = 0;
        while(b<j)
        {
            if(man[b] > ave)
                count++;
            b++;
        }
        printf("%3.3f%c\n",(float)((count*100.0)/(float)j),37);

    }
    return 0;

}
