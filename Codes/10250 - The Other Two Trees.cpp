#include<stdio.h>
int main()
{
    double x1,x2,y1,y2;
    double mx,my;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)==4){
        mx = (x1+x2)/2;
        my = (y1+y2)/2;
        printf("%lf %lf %lf %lf\n",mx-my+y1,my+mx-x1,mx+my-y1,my-mx+x1);
    }
    return 0;
}
