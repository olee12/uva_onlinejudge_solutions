#include<stdio.h>
int main()
{
    int i,j=0;
    while(scanf("%d",&i)){
        if(!i) break;
        while(i>=3)
            j+=i/3,i=(i/3)+(i%3);
            if(i==2) j++;
            printf("%d\n",j);
            j=0;
    }
    return 0;
}
