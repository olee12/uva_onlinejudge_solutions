#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void dfs(int i,int j);
int store[300];
char ara[50][50];
char ch;
int row,col;
int count;

typedef struct
{
    char ch;
    int value;
} ID;

ID id[50];

int comp(const void* a, const void* b)
{
    ID* c = (ID*)a;
    ID* d = (ID*)b;

    if(c->value != d->value)
        return d->value - c->value;
    else return c->ch - d->ch;
}
int main()
{
    int i,j,k,l=0,t,q;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&row,&col);
            for(i=0; i<row; i++) scanf("%s",ara[i]);
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    ch=ara[i][j];
                    dfs(i,j);
                    store[ch]++;
                    count=0;
                }
            }

            for(i=97,q=0; i<=122; i++)
                if(store[i]) id[q++] = {i, store[i]};

            qsort(id, q, sizeof(ID), comp);

            for(i=0; i<q; ++i)
                printf("%c: %d\n",id[i].ch,id[i].value);

        }
    }

}
void dfs(int i,int j)
{
    if(i<0 || j<0 || i>=row || j>=col) return ;
    if(ara[i][j]!= ch || ara[i][j]=='.') return ;
    ara[i][j]='.';
    count++;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dfs(int i,int j);
int store[300];
char ara[50][50];
char ch;
int row,col;
int count;

typedef struct
{
    char ch;
    int value;
} ID;

ID id[50];

int comp(const void* a, const void* b)
{
    ID* c = (ID*)a;
    ID* d = (ID*)b;

    if(c->value != d->value)
        return d->value - c->value;
    else return c->ch - d->ch;
}
int main()
{
    int i,j,k,l=0,t,q;
    while(scanf("%d",&t)==1)
    {
        k=1;
        while(t--)
        {
            scanf("%d %d",&row,&col);
            for(i=0; i<row; i++) scanf("%s",ara[i]);
            for(i=0; i<row; i++)
            {
                for(j=0; j<col; j++)
                {
                    ch=ara[i][j];
                    dfs(i,j);
                    store[ch]++;
                    count=0;
                }
            }
            printf("World #%d\n",k++);
            for(i=97,q=0; i<=122; i++)
                if(store[i])
                {
                    id[q].ch = i;
                    id[q].value=store[i];
                    q++;
                    store[i]=0;
                };

            qsort(id, q, sizeof(ID), comp);

            for(i=0; i<q; ++i)
                printf("%c: %d\n",id[i].ch,id[i].value),id[i].ch=0,id[i].value=0;

        }
    }
    return 0;

}
void dfs(int i,int j)
{
    if(i<0 || j<0 || i>=row || j>=col) return ;
    if(ara[i][j]!= ch || ara[i][j]=='.') return ;
    ara[i][j]='.';
    count++;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
*/
