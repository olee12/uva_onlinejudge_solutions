#include<stdio.h>
#include<string.h>
int main()
{
    char str[21][3][105];
    char tst[105];
    int i,j,k,l,n,t;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf(" %[^\n]",&str[i][0]);
            scanf(" %[^\n]",&str[i][1]);
        }
        scanf(" %d",&t);
        while(t--){
            scanf(" %[^\n]",tst);
            for(i=0;i<n;i++){
                if(!strcmp(str[i][0],tst)){
                    printf("%s\n",str[i][1]);
                    break;
                }
            }
        }
    }
    return 0;
}
