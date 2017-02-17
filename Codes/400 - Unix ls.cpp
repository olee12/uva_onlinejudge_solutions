#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    string str;

    int N;
    int maxs;
    while(scanf("%d",&N)==1)
    {
        vector<string> v;
        maxs=0;
        for(int i=0; i<N; i++)
        {
            cin>>str;
            v.push_back(str);
            if(v[i].size() > maxs) maxs=v[i].size();
        }
        sort(v.begin(),v.end());
        int col = 62 / (maxs+2);
        int row = ceil(N / (double)col);
        int spece = maxs+2;

        printf ("------------------------------------------------------------\n");
        for(int i=0; i<row; i++)
        {
            for(int j = i; j<N; j+=row)
            {
                cout<<v[j];
                if(j + row < N)
                {
                    for(int k = v[j].size(); k<spece; k++) printf(" ");
                }
            }
            printf("\n");
        }

    }
    return 0;

}
