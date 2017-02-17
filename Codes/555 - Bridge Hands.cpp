#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstdlib>
#include<string>
using namespace std;
class game
{
public:
    char card;
    char pos;
    int cardpos;
    int num;
    void set_card(char ch, char ch2);
};
void game::set_card(char ch, char ch2)
{
    if(ch=='C') cardpos = 1;
    else if(ch == 'D') cardpos = 2;
    else if(ch == 'S') cardpos = 3;
    else cardpos = 4;
    card = ch;
    if(ch2 >= '2' && ch2 <='9')  num = ch2 - '1';
    else if (ch2 == 'T') num = 9;
    else if(ch2 == 'J') num = 10;
    else if(ch2 == 'Q') num = 11;
    else if(ch2 == 'K') num = 12;
    else if(ch2 == 'A') num = 13;
    pos = ch2;

}
class player
{
public:
    game ara2[14];

} ara1[4];
int comp(const void *a,const void *b)
{
    game *c = (game *)a;
    game *d = (game *)b;
    if(c->cardpos == d->cardpos)
    {
        return c->num - d->num;
    }
    else if (c->cardpos != d->cardpos)
        return c->cardpos - d->cardpos;
}
int main()
{
    char ch;

    char  in;
    int dis;
    while(scanf(" %c ",&ch)!=EOF && ch != '#')
    {
        char str[200];
        if(ch == 'N') dis = 1;
        else if(ch == 'E') dis = 2;
        else if(ch == 'S') dis = 3;
        else if(ch == 'W') dis = 4;
        gets(str);
        gets(str+52);
        int v=0,b=0,n=0,m=0;
        dis%=4;
        for(int i = 0; i<104; i+=2)
        {
            if(dis == 0)
                ara1[dis].ara2[v++].set_card(str[i],str[i+1]);
            if(dis == 1)
                ara1[dis].ara2[b++].set_card(str[i],str[i+1]);
            if(dis == 2)
                ara1[dis].ara2[n++].set_card(str[i],str[i+1]);
            if(dis == 3)
                ara1[dis].ara2[m++].set_card(str[i],str[i+1]);
            dis++;
            dis = dis &3;

        }
        for(int i = 0; i<4; i++)
        {
            qsort(ara1[i].ara2,13,sizeof(game),comp);
        }
        printf("S:");
        for(int j = 0; j<13; j++)
            printf (" %c%c",ara1[2].ara2[j].card,ara1[2].ara2[j].pos);
        printf("\nW:");
        for(int j = 0; j<13; j++)
            printf (" %c%c",ara1[3].ara2[j].card,ara1[3].ara2[j].pos);
        printf("\nN:");
        for(int j = 0; j<13; j++)
            printf (" %c%c",ara1[0].ara2[j].card,ara1[0].ara2[j].pos);
        printf("\nE:");
        for(int j = 0; j<13; j++)
            printf(" %c%c",ara1[1].ara2[j].card,ara1[1].ara2[j].pos);
        printf("\n");
    }
    return 0;
}

