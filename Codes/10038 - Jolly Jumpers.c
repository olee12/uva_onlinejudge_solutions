/*#include <stdio.h>
int a[3020];
int main()
{

    int n,i,k,t;
    while(scanf("%d",&n)==1)
    {
        t=0;
        int b[3020]= {0};
        scanf("%d",&a[1]);

        for(i=2; i<=n; i++)
        {
            scanf("%d",&a[i]);
            k=a[i]-a[i-1];
            if(k<0)
                k*=-1;
            b[k]=1;
        }
        for(i=1; i<=n-1; i++)

            if(b[i]!=1)
            {
                t=1;
                break;
            }
        if(t==0 )
            printf("Jolly\n");
        else
            printf("Not jolly\n");

    }
    return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[3020];

    int i,c,k,n;
    while(scanf("%d",&n)==1){
        int b[3020]={0};
        c=1;
        scanf("%d",&a[1]);
        for(i=2;i<=n;i++){
            scanf("%d",&a[i]);
            k = abs(a[i]-a[i-1]);
            b[k]=1;
        }
        for(i=1;i<=n-1;i++){
            if(b[i]!=1){
                c=0;
                break;
            }
        }
        if(c) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
