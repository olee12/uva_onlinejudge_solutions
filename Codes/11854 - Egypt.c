#include <stdio.h>

int main()
{
    int side1, side2, side3;

    while(scanf("%d %d %d", &side1,&side2, &side3)==3)
    {
        if(side1==0 && side2==0 && side3==0)
            break;

         if(side1<=0 || side2<=0 ||side3<=0)
            printf("wrong\n");
        else if(side1*side1==side2*side2+side3*side3)
            printf("right\n");
        else if(side2*side2==side1*side1+side3*side3)
            printf("right\n");
        else if(side3*side3==side2*side2+side1*side1)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}
