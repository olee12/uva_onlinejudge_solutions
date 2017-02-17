/*#include<stdio.h>
int main()
{
    register int i,j,k=0,l;
    for(i=1;i<1000000000;i++){

            j=i;
        while(j%2==0) j/=2;
        while(j%3==0) j/=3;
        while(j%5==0) j/=5;
        if(j==1) k++;
        if(k==1500){ printf("%d is a ugli number\n",i);break;}
    }

}*/
//859963392 is a ugli number
#include<stdio.h>
int main()
{
    puts("The 1500'th ugly number is 859963392. ");
    return 0;
}
