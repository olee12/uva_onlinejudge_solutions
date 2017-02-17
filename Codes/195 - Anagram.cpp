#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    //map<int ,char> mp;
    int up,lo,val;
    int ara[500];
    map<int,char> mp;
    char str[100];
    while(test--)
    {
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0; i<len; i++)
        {
            val = str[i];
            if(str[i]>='A' && str[i]<='Z')
            {
                val = val*2;

            }
            else
            {
                val = 131+2*(val-'a');
            }
            mp[val] = str[i];
            ara[i] = val;
            //cout<<mp[val]<<endl;

        }
        sort(ara,ara+len);
        do
        {
            for(int i = 0; i<len; i++)
            {
                //  cout<<mp[ara[i]];
                printf("%c",mp[ara[i]]);
            }
            puts("");
        }
        while(next_permutation(ara,ara+len));

    }
    return 0;
}
