#include<stdio.h>
int main()
{
    int day=0;
    float h,u,d,f,x,climb=0;
    while(scanf("%f %f %f %f",&h,&u,&d,&f)==4 && h)
    {

        x = (u*(f/100));
        while(climb<=h && climb>=0)
        {
            climb += u;
            u-=x;
            if(climb<=h) climb -= d;
            day++;
            if(u<0) u=0;
            if(climb>=h)
            {
                printf("success on day %d\n",day);
                break;
            }
            if(climb<0)
            {
                printf("failure on day %d\n",day);
                break;
            }
        }
        day=0,climb=0;
    }
    return 0;
}
