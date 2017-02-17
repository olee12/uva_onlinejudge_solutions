#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;
typedef struct
{
    int num=0;
    char ch;
} letter;
letter str[100];
int comp(const void *a,const void *b);
int main()
{
    int line;
    char c,n;
    int newline;
    scanf("%d",&line);

        n=getchar();
        while(line)
        {
            c=toupper(getchar());
            if(c=='\n') line--;
            if(isalpha(c))
            {
                str[c-65].ch=c;
                str[c-65].num++;
            }
        }
        qsort(str,26,sizeof(letter),comp);
        for(int i=0; str[i].num!=0; i++)
        {
            printf("%c %d\n",str[i].ch,str[i].num);
            str[i].num=0;
        }

    return 0;
}

int comp(const void *a,const void *b)
{
    letter *c = (letter*)a;
    letter *d = (letter*)b;
    if(c->num != d->num) return d->num - c->num;
    return c->ch-d->ch;
}
