#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int comp(const void *a,const void *b);
int main()
{
    long long int a[5];
   int t,i;
    while(scanf("%lld",&t)==1){
        while(t--){
            for(i=0;i<4;i++) scanf("%lld",&a[i]);
            qsort(a,4,sizeof(long long int),comp);

            if(a[0]<(a[1]+a[2]+a[3])){
              if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) printf("square\n");
            else if(a[0]==a[1]&&a[2]==a[3])
                printf("rectangle\n");
                else
                    printf("quadrangle\n");
               }
               else printf("banana\n");

        }
    }
    return 0;
}
int comp(const void *a,const void *b)
{
    return(*(int*)b-*(int*)a);
}
