#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int h1,h3,h2,h4,m1,m2,m3,m4;
    int t;
    int a,c,b,d;
    int cas;
    scanf("%d",&t);
    cas=1;
    while(t--){

        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        scanf("%d:%d %d:%d",&h3,&m3,&h4,&m4);
        a=h1*60+m1;b=h2*60+m2;c=h3*60+m3;d=h4*60+m4;
        if(c>=a){
            if(d<=b) printf("Case %d: Mrs Meeting\n",cas++);
            else if(c>b) printf("Case %d: Hits Meeting\n",cas++);
            else printf("Case %d: Mrs Meeting\n",cas++);
        }
        else if(c<a){
            if(d>=a && d<= b) printf("Case %d: Mrs Meeting\n",cas++);
            else if(d>b) printf("Case %d: Mrs Meeting\n",cas++);
            else printf("Case %d: Hits Meeting\n",cas++);
        }
    }
    return 0;
}
