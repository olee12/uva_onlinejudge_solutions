#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    map<string , int > mp;
    for(int p, g; scanf("%d %d",&p,&g)==2;){
        char word[50],com[50];
        for(int v1,v2; p-- && scanf("%s %d.%d",word,&v1,&v2)==3;){
            mp[word]=(v1*10)+v2;
        }
        int correct,sum=0;
        for(int a=0,v;a++<g;){
            while(true){
                scanf("%s %s",word,com);
                sum+=mp[word];
                if(*com=='+')continue;
                scanf("%d",&v);
                v*=10;
                if(*com == '<'){
                    if(*(com+1)=='=') correct = sum <= v;
                    else correct = sum < v;

                }else if(*com == '>')
                {
                    if(*(com+1)=='=') correct= sum >= v;
                    else correct = sum > v;
                } else correct = sum == v;
                printf("Guess #%d was %s.\n",a, correct?"correct" : "incorrect");
                sum=0;
                break;

            }

        }
    }
    return 0;

}
