#include<stdio.h>
int main()
{
    int t,n,k,p;
    int i,j;
    while(scanf("%d",&t)==1){
            j=1;
        while(j<=t){
            scanf("%d %d %d",&n,&k,&p);
            for(i=0;i<p;i++){
                if(k==n) k=1;
                else
                k++;


            }
            printf("Case %d: %d\n",j++,k);
        }
    }
    return 0;
}
