#include<stdio.h>
int main()
{
    int a[14];
    int b[14];
    int i,j=1,k,l,m,n;
    while(scanf("%d",&a[0])&&a[0]>=0){
        for(i=1;i<13;i++) scanf("%d",&a[i]);
        for(i=0;i<12;i++) scanf("%d",&b[i]);
        printf("Case %d:\n",j++);
        for(i=0;i<12;i++){
            if(a[0]>=b[i]) printf("No problem! :D\n"),a[0]-=b[i];
            else printf("No problem. :(\n");
            a[0]+=a[i+1];
        }
    }
    return 0;
}

