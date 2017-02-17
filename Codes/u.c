#include<stdio.h>
int f91(int a);

int main()
{
    int a;
    for (;scanf("%d",&a); ){
    if (a==0){
            break;
    }//f91(500) = 490
    printf("f91(%d) = %d\n",a,f91(a));
}
return 0;
}
int f91(int a)
{
    if(a<=100) f91(f91(a+11));
    if(a>=101) return (a-10);

}
