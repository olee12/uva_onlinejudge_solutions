#include<stdio.h>
int main()
{
    long long int j;
    int i,sum,n;
    while(scanf("%d",&n)==1 && n){
            sum = 0;
        for(i=1;i<=n;i++){
                j = i*i;
            sum+=j;
        }
        printf("%d\n",sum);

    }
    return 0;
}
