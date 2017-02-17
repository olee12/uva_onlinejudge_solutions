#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int i, j, n, a, cas=1;
    cin >> n;
    while(n--)
    {
        cin >> a;
        printf("Case #%d: %d", cas++, a);
        for (i=2,j=0; j<2; i++)
        {
            if (a%i == 0)
            {
                j++;
                printf(" = %d * %d", i, a/i);
            }
        }
        printf("\n");
    }
    return 0;
}
