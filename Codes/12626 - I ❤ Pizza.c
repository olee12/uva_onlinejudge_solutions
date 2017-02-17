#include<stdio.h>
int main()
{
    int m,a,r,g,i,t,p,j,k;
    char ch;
    while(scanf("%c",&ch)==1){
        if(ch=='M') m++;
        else if(ch=='A') a++;
        else if(ch=='R') r++;
        else if(ch=='G') g++;
        else if(ch=='I') i++;
        else if(ch=='T') t++;

    }
    if(m<1 && a<3 && r<2 && g<1 && i<1 && t<1)
        printf("0\n");
    else if(m>=1 && a>=3 && r>=2 && g>=1 && i>=1 && t>=1)
    {
        if((m/1)>=(a/3)>=(r/2)>=(g/1)>=(i/1)>=(t/1))
            printf("%d\n",r/2);
        else{
            printf("%d\n",r/2-1);
        }
    }

}

