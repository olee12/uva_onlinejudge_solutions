#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    bin(i);

}
void bin(int a)
{
    if(a==1){
        printf("%d",1);
        return;

    }
    bin(a/2);
    printf("%d",a%2);
}
