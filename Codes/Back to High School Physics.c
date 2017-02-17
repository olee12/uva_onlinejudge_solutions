#include <stdio.h>
int main()
{
    int j;
    int i;
    int s;

    while((scanf("%d %d",&i,&j))==2)
    {
        s = 2*j*i;
        printf("%d\n", s);

    }
    return 0;
}
