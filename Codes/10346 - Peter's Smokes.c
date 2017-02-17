#include<stdio.h>
int main()
{
    int i,j,k;
    while(scanf("%d %d",&i,&k)==2)
    {
        j = i;
        while(i>=k)
        {
            j = j + (i/k);
            i = (i/k) + (i%k);
        }
        printf("%d\n",j);
    }
    return 0;
}

