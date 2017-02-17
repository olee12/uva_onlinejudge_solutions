#include<stdio.h>
#include<math.h>
int main()
{
    int h,m,t;
    while(scanf("%d",&t)==1){
        while(t--){
            scanf("%d:%d",&h,&m);
            h = 11 - h +(m==0);
            if(h<=0) h = 12 + h;
            if(m!=0) m = 60 - m;
            printf("%02d:%02d\n",h,m);
        }

    }
    return 0;
}
