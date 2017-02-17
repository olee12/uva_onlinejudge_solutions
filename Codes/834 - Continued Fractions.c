//#include<stdio.h>
//int main()
//{
//    int a,b,c,i,j,k,l=0;
//    while(scanf("%d %d",&a,&b)==2)
//    {
////        if(a==1 && b ==2)
////        {
////            printf("[0;2]\n");
////
////        }
////        else
//        while(1)
//        {
//            if(a ==1 && b == 2)
//            {
//                printf("[0;2]\n");
//                break;
//            }
//            if(b>a)
//            {
//                k = b;
//                b=a;
//                a=k;
//            }
//            if(b!=0)
//                c = a/b;
//            l++;
//
//            if(l==1)
//                printf("[%d;",c);
//            else if(l!=1 && a!=1)
//            {
//                printf("%d,",c);
//
//            }
//            a = a%b;
//            if((a%b)==0)
//            {
//                printf("\b]\n");
//                break;
//            }
//            if(((float)a/(float)b) == 0.5)
//            {
//                printf("\b,2]\n");
//                break;
//            }
//            if(a==1 && b >= 1 )
//            {
//                printf("%d]\n",b);
//                break;
//            }
//        }
//        l=0;
//    }
//    return 0;
//}
//


#include<stdio.h>
int main()
{
     int a,b,c,k;


    while(scanf("%d%d",&a,&b)==2)
    {
        k=0;
        while(b)
        {
            switch(k)
            {
            case 0:
                printf("[%d",a/b);
                break;
            case 1:
                printf(";%d",a/b);
                break;
            default:
                printf(",%d",a/b);
                break;
            }
            c = b;
            b = a%b;
            a = c;
            k++;
        }
        printf("]\n");
    }
    return 0;
}
