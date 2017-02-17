#include<stdio.h>
#include<string.h>
int main()
{
    int t,p,n,i,j,k;
    char ch,par[102];
    int cnt[102];
    double sum=0;
    scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&p);
            for(i=0; i<p; i++)
            {
                scanf(" %c %d",&par[i],&cnt[i]);
            }
            par[i]='\0';

            scanf("%d",&n);
            i=0;
            n++;
            while(n)
            {
                ch=getchar();
                if(ch=='\n'){
                    n--;
                }
                for(k=0; k<p; k++)
                {
                    if(ch==par[k])
                    {
                        sum+=cnt[k];
                    }
                }
            }
            sum=sum/100.00;
            printf("%.2lf$\n",sum);
            sum=0,i=0,j=0;
        }
    return 0;
}
