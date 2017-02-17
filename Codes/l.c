#include<stdio.h>
int rec(int a, int b)
{
    if(b<=0)
        return 1;
    int n = a+b;
    printf("a = %d b.= %d res = %d\n",a,b,n);
    n = rec(b+1,a%b)+rec(b-1,(a%b)-1);
    printf("a = %d b = %d res = %d\n",a,b,n);
    return n;
}
int main()
{
    rec(2,4);

}
//#include<stdio.h>
//int main()
//{
//    int a,i,j;
//    scanf("%d",&a);
//    int ara1[a];
//    int ara2[a];
//    for(i=0;i<a;i++){
//        scanf("%d",&ara1[i]);
//    }
//    for(i = 0;i<a;i++){
//        scanf("%d",&ara2[i]);
//    }
//    for(i=0,j=(a-1);i<a;i++,j--){
//        printf("%d ",ara1[i]+ara2[j]);
//    }
//
//}
#include<stdio.h>
#define SZ 1+3
#define SZ2 2*SZ
int main()
{
    int i,j,n=6;
    for(i=0;i<n;i++){
        for (j=1;j<=4 ;j++ ){
            if(i%((i%j)+1)!=0&&i%((i%j)+1)!=3)
                printf("@ i = %d j=%d ,res = %d\n",i,j,i%((i%j)+1));
        }
            ;
    }

printf("%d\n",SZ2);
printf("DATA %d\n",i*SZ2*j);
}
