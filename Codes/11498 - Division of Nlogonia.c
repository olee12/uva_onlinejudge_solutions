#include<stdio.h>
int main()
{
    int t,m,n,x,y,i,j,k,l;
    while(scanf("%d",&t)==1&&t){
        scanf("%d %d",&m,&n);
        while(t--){
            scanf("%d %d",&x,&y);
            if(x==m||y==n) printf("divisa\n");
            else if(x>m && y>n) printf("NE\n");
            else if(x<m && y>n) printf("NO\n");
            else if(x<m && y<n) printf("SO\n");
            else if(x>m&&y<n) printf("SE\n");
        }
    }
    return 0;
}
