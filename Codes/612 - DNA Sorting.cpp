#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int comp(const void *a,const void *b);
int bouble(char *str);
typedef struct
{
    int count;
    char str[80];
} ID;
ID ara[150];
bool compe(ID a,ID b);
int main()
{
    int i,j,k,l;
    char str[80];
    int data,len,test;
    scanf("%d",&data);
            getchar();
        while(data--){
            scanf("%d %d",&len,&test);
            for(i=0;i<test;i++){
                scanf(" %s",ara[i].str);
                ara[i].count=bouble(ara[i].str);
               // cout<<ara[i].count<<endl;
            }
            qsort(ara,test,sizeof(ID),comp);
           //stable_sort(ara,ara+test,compe);

            for(i=0;i<test;i++) cout<<ara[i].str<<endl;
            if(data!=0) cout<<endl;

        }

    return 0;
}

int bouble(char *str)
{
    int inverse=0;
    int len=strlen(str);
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(str[j]<str[i]) inverse++;
        }

    }
    return inverse;
}
int comp(const void *a,const void *b)
{
    ID *c= (ID*)a;
    ID *d= (ID*)b;

    return  (c->count - d->count);
}

bool compe(ID a,ID b)
{

    if(a.count!=b.count)
    return a.count<b.count;
    return 0;
}
