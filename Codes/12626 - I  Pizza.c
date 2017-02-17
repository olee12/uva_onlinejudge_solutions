#include<stdio.h>
#include<string.h>
int min(int *a)
{
    int i,min=a[0];
    for(i=0; i<6; i++)
        if(a[i]<min)
            min=a[i];
    return min;
}
int main()
{
    int n,i;
    char b[605];
    scanf("%d",&n);
    while(n--)
    {
        int a[6]= {0};
        scanf("%s",b);
        for(i=0; i<strlen(b); i++)
        {
            if(b[i]=='M') a[0]++;
            if(b[i]=='A') a[1]++;
            if(b[i]=='R') a[2]++;
            if(b[i]=='G') a[3]++;
            if(b[i]=='I') a[4]++;
            if(b[i]=='T') a[5]++;
        }
        a[1]/=3;
        a[2]/=2;
        printf("%d\n",min(a));
    }
    return 0;
}
