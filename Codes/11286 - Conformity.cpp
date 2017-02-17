#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main()
{

    int frosh;
    int i ,j,k,l;
    int num;

    while(scanf("%d",&frosh),frosh)
    {
        map<vector<int>,int> course_popularity;
        for(i=0; i<frosh; i++)
        {
            vector<int> v;
            scanf("%d",&num);
            v.push_back(num);
            scanf("%d",&num);
            v.push_back(num);
            scanf("%d",&num);
            v.push_back(num);
            scanf("%d",&num);
            v.push_back(num);
            scanf("%d",&num);
            v.push_back(num);
            sort(v.begin(),v.end());
            course_popularity[v]++;
        }
        int max=0,student=0;
        for(map<vector<int>,int> :: iterator it = course_popularity.begin();
                it!=course_popularity.end(); it++)
        {
            if(it->second > max)
            {
                max = it->second;
                //cout<<max<<endl;
                student = 0;
            }
            if(it->second == max)
            {
                student += max;
                //cout<<student<<endl;
            }

        }
        printf("%d\n",student);
    }
}
