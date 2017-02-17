#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int test,N,Q,x,a,big;
    scanf("%d",&test);
    while(test--){
            big = 0;
        scanf("%d %d",&N,&Q);
        for(int i = 0;i<N;i++) {
                scanf("%d",&x);
                big|=x;
        }
        int max;
        while(Q--){
            max=0;
            scanf("%d",&a);
            /*for(int i =0;i<N;i++){
                if((a&x[i])  > max) max = (a&x[i]);*/
                printf("%d\n",big&a);

            }
        }

    return 0;
}
