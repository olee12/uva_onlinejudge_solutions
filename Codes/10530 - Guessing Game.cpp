#include<stdio.h>
#include<string.h>

bool hons[12];

int main()
{
    char ans[20];
    int a,i,k;
    //freopen("in.txt","r",stdin);

    while(scanf("%d\n",&a)&&a)
    {
        for(i=0; i<12; i++)
            hons[i]=true;
        while(1)
        {
            gets(ans);
            if(!strcmp(ans,"right on"))
                break;

            if(!strcmp(ans,"too high"))
                for(k=a; k<11; k++)
                    hons[k]=false;
            else
                for(k=a; k>0; k--)
                    hons[k]=false;

            scanf("%d\n",&a);
        }
        if(hons[a])
            printf("Stan may be honest\n");
        else
            printf("Stan is dishonest\n");
    }
    return 0;
}
