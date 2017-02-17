#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<iterator>
#include<cstdio>
#include<map>
using namespace std;
typedef struct
{
    string license;
    int toll;
    int time;
    int location;
    int enter;

} car;
car P[1005];
bool comp(car a,car b)
{
    if(a.license != b.license) return a.license<b.license;
    else return a.time<b.time;
}
int main()
{
    int n,i,j,k;
    char str[1000],nam[1000],enter[50];
    int toll[24];
    int testcase;
    scanf("%d",&testcase);
    int dd,mm,hh,loc;
    while(testcase--)
    {
        for(i=0; i<24; i++) scanf("%d",&toll[i]);

        while(getchar()!='\n');
        n=0;
        car tmp;
        while(gets(str))
        {
            if(str[0]=='\0') break;
            sscanf(str,"%s %*d:%d:%d:%d %s %d",nam,&dd,&hh,&mm,enter,&loc);
            P[n].license=nam;
            P[n].time= dd*24*60+hh*60+mm;
            P[n].location=loc;
            P[n].enter = (enter[1]== 'n');
            P[n].toll=toll[hh];
            n++;
        }
        sort(P,P+n,comp);

        map<string,int> bill;
        for(i=0; i<n; i++)
        {
            if( P[i].enter == 1 )
            {
                for(j=i; j<n; j++)
                {
                    if( P[j].license != P[i].license ) break;
                    if( P[i].license == P[j].license && P[j].enter == 0 )
                    {
                        bill[ P[j].license ] += abs( P[j].location - P[j-1].location) * P[j-1].toll + 100;
                        j++;
                        break;
                    }

                }
                i=j-1;
            }

        }
        for(map<string,int> :: iterator it = bill.begin(); it!=bill.end(); it++)
        {
            cout<<it->first<<' '<< '$';
            printf("%d.%02d\n",(it->second+200)/100,(it->second + 200)%100 );
        }
        if(testcase) printf("\n");

    }


}
