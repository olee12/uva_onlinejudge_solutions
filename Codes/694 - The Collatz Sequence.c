#include<stdio.h>

int main()
{
    long long int a,l,i,k=0,m=0,n,c=0;
    while(scanf("%lld %lld",&a,&l)==2 && a>0&&l>0){
            i=a;
        while(a<=l){
            if(a==1){
                c++;
                break;
            }
            if(!(a%2)) c++,a/=2;
            else if(a%2) c++,a=(a*3)+1;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++k,i,l,c);
        c=0;
    }
    return 0;
}
