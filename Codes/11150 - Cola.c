#include<stdio.h>
int main()
{
    int i,j;
    while(scanf("%d",&i)==1)
    {
        j = i;
        while(i>=3)
        {
           // j = j + (i/3);
          //  i = (i/3) + (i%3);
          j+=i/3,i=(i/3)+(i%3);
        }
        if(i == 2)
        {
            j++;
        }
        printf("%d\n",j);
    }
    return 0;
}
