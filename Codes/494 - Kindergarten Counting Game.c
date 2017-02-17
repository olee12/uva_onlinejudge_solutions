#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    int f,w,c,i;
    while(gets(a)){
        c=0;
        w=1;
        i=0;
        while(a[i]){
            if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<'z')){
                if(w){
                    c++;w=0;
                }
            }
            else w=1;
            i++;
        }
        printf("%d\n",c);
    }
}
