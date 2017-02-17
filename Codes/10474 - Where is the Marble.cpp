#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int comp(const void * a, const void *b)
{
    return *(int *)a - *(int *)b;

}
int main()
{
    int N,Q;
    int ara[10005];
    int cas=1,pos;
    int num;
    while(scanf("%d %d",&N,&Q) && N && Q)
    {
        printf("CASE# %d:\n",cas++);
        for(int i = 0; i<N; i++) scanf("%d",&ara[i]);

        sort(ara,ara+N);

        while(Q--)
        {
            scanf("%d",&num);
            if(bsearch(&num,ara,N,sizeof(int),comp))
            {
                pos = lower_bound(ara,ara+N,num) - ara +1;
                printf("%d found at %d\n",num,pos);
            }
            else
            {
                printf("%d not found\n", num);
            }


        }
    }
    return 0;
}
