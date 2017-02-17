#include <stdio.h>
int main()
{
    int test, cnt = 0;
    double ara[5];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf%lf%lf%lf", ara, ara+1, ara+2, ara+3);
        if(((ara[0] <= 56 && ara[1] <= 45 && ara[2] <= 25) || (ara[0] + ara[1] + ara[2] <= 125)) && ara[3] <= 7 ) puts("1"), cnt++;
        else puts("0");
    }
    printf("%d\n", cnt);
    return 0;
}
