#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100];
    int a=0,s=0,t;
   scanf("%d",&t);
    {
        while(t--)
        {
            scanf("%s",str1);
            if(!strcmp(str1,"donate"))
            {
                scanf("%d",&a);
                s+=a;
            }
            else printf("%d\n",s);

        }
    }
    return 0;

}
