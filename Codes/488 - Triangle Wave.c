//#include<stdio.h>
//int main()
//{
//    int a,b;
//    int i,j,k;
//    scanf("%d",&k);
//
//        while(k--)
//        {
//            scanf("%d",&a);
//            scanf("%d",&b);
//            while(b--)
//            {
//                for(i=1; i<2*a; i++)
//                {
//                    if(i<=a)for(j=1; j<=i; j++)
//                            printf("%d",i);
//                    else
//                        for(j=0; j<2*a-i; j++)
//                            printf("%d",2*a-i);
//                    printf("\n");
//                }
//                if(k)
//                printf("\n");
//            }
//        }
//
//    return 0;
//
//}
#include <stdio.h>

int main()
{
    int lenth, hig, a, i, j, k, t;
    scanf("%d", &t);
    for(a=0; a<t; a++)
    {
        scanf(" %d %d", &hig, &lenth);
        {
            for(i=0; i<lenth; i++)
            {
                for(j=1; j<hig; j++)
                {
                    for(k=1; k<=j; k++)
                        printf("%d", j);
                    printf("\n");
                }
                for(k=hig-1; j>=1; j--)
                {
                    for(k=1; k<=j; k++)
                        printf("%d", j);
                    printf("\n");
                }
                if(i!=(lenth-1))printf("\n");
            }
            if(a!=(t-1))printf("\n");
        }
    }
    return 0;
}
