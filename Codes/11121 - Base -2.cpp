#include<bits/stdc++.h>
using namespace std;
void bin(int a);
int main()
{
    int ara[10000];
    int test;
    int cas;
    int i;
    //cout<<(-3)/(-2);
    scanf("%d",&test);
    int num;
    for(int cas=1;cas<=test;cas++){
        ara[0]=0;i=-1;
        scanf("%d",&num);
        while(num){
            ara[++i]=num%(-2);
            num/=(-2);
            if(ara[i]==-1){
                ara[i]=1;num++;
            }
        }
        printf("Case #%d: ",cas);
        while(i>0) printf("%d",ara[i--]);
        printf("%d",ara[0]);
        puts("");
    }
    return 0;

}
void bin(int a)
{
    if(a%-2==-1) printf("1"), a++;
    if(a==0) return ;
    bin(a/(-2));
    if(a%-2==-1) printf("1");
    else
    printf("%d",a%-2);
}

