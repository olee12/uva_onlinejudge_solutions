#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char tmp[2000];
bool ispalin(const char* a, const char* b)
{
    strcpy(tmp, a);
    strcat(tmp, b);
    for(int i = 0, j = strlen(tmp),
            l = (j--) >> 1; i <= l; ++i, --j)
        if(tmp[i] != tmp[j]) return false;
    return true;
}
char word[1001][1000];
int main()
{
    int tc, n;
    scanf("%d", &tc);
    for(int t = 1, pcount; t <= tc; ++t)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf(" %s", word[i]);
        pcount = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(ispalin(word[i], word[j])) ++pcount;
                if(ispalin(word[j], word[i])) ++pcount;
            }
        }
        printf("Case #%d: %d\n", t, pcount);
    }
    return 0;
}
