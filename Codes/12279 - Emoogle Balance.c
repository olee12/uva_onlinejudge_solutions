#include<stdio.h>
int main()
{
    int ara[1010];
    int i,j=0,l=0,k,c=1,m;
    while(scanf("%d",&k)==1 && k){
        for(i=0;i<k;i++){
            scanf("%d",&ara[i]);
            if(ara[i]==0) j++;
            else l++;

        }
        m=l-j;

        printf("Case %d:",c++);
        printf(" %d\n",m);
        l=0;
        j=0;

    }
    return 0;
}
