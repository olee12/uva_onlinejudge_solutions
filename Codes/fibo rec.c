#include<Stdio.h>
int main()
{
    int n,j;
    scanf("%d",&n);
    j = fibon(n);
    printf("%d ",j);
}

int fibon(int n)
{
    if(n<=1)
        return 1;
    int res;
    res = fibon(n-1)+fibon(n-2);
    return res;
}
