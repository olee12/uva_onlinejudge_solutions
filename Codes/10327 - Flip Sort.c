/*#include<stdio.h>
int main()
{
    int *p;
    int t,f=0,i,j;
    while(scanf("%d",&t)==1)
    {
        p=(int *)malloc(t*sizeof(int));
        for(i=0; i<t; i++) scanf("%d",&p[i]);

        for(i=0; i<t-1; i++)
        {
            for(j=i+1; j<t; j++)
                if(p[i]>p[j])
                {
                    f++;
                }
        }
        printf("Minimum exchange operations : %d\n",f);
        f=0;
    }
    return 0;

}
*/

#include<stdio.h>
int main()
{

    int n,c,t,i,j;
    int ar[1010];

    while(scanf("%d",&n)!=EOF)

    {
        c=0;


        for (i= 0; i<n; i++)
        {
            scanf("%d", &ar[i]);
        }

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                 t=ar[j];
                ar[j]=ar[i];
                ar[i]=t;
                c++;
            }
        }
        printf("Minimum exchange operations : %d\n",c);





    }

    return 0;
}
