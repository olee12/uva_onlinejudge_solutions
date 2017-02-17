#include<string>
#include<iostream>
#include<map>
#include<iterator>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct
{
    string gru;
    int num;
} data;

bool comp(data a,data b)
{
    if(a.num >  b.num) return 1;
    else if(a.num < b.num) return 0;
    else if(a.gru < b.gru) return 1;
    else return 0;
}
int main()
{
    data ara[110];
    int i,j,k,l;
    string input;
    map<string,int> grupe;
    map<string,int> student;
    map<string,string>cheak;
    map<string , int> extra;
    string gr;
    string user;
    i=0;
    while(getline(cin,input))
    {
        if(input=="0") break;
        if(input!="1")
        {
            if('A' <= input[0] && input[0] <='Z')
            {
                gr=input;
                grupe[gr]=0;
            }
            else
            {
                j = ++student[input];

                if(j==1)
                {
                    cheak[input]=gr;
                }
                else if(j>2 )
                {
                    if(cheak[input]==gr){

                        continue;
                    }
                        if(cheak[input]!=gr){
                            if(!extra[input]){
                                extra[input]++;
                            if(grupe[cheak[input]]>0)
                            grupe[cheak[input]]--;
                            }
                        }

                    else
                    {
                        if(grupe[cheak[input]]>0)
                            grupe[cheak[input]]--;
                    }
                }
                else
                {
                    if(cheak[input]==gr)
                        continue;
                    else
                    {
                        extra[input]++;
                        if(grupe[cheak[input]]>0)
                            grupe[cheak[input]]--;
                    }
                }

                if(cheak[input]==gr)
                {
                    grupe[gr]++;
                }

            }

        }
        else
        {
            i=0;
            for(map<string,int> :: iterator it=grupe.begin(); it!=grupe.end(); it++)
            {
                ara[i].gru=it->first;
                ara[i].num=it->second;
                i++;
            }

            sort(ara,ara+i,comp);
            for(j=0; j<i; j++)
            {
                printf("%s %d\n",ara[j].gru.c_str(),ara[j].num);
            }
            grupe.clear();
            cheak.clear();
            student.clear();
        }

    }
    return 0;


}
