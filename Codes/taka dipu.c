#include<stdio.h>
int main()
{
    int note[] = {1000,500,100,50,20,10,5,2,1};
    int i,tk;
    int pre[9];
    while(1){
    scanf("%d",&tk);
    for(i=0;i<9;i++){
        pre[i] = tk / note[i];
        tk = tk % note[i];
        if(!pre[i]) continue;
        printf("%d taka : %d\n", note[i],pre[i]);
    }
    }
    return 0;
}
