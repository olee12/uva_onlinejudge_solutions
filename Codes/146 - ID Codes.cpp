#include<cstdio>
#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char str[100];
    while(gets(str)){
        if(str[0]=='#') break;
        if(next_permutation(str,str+strlen(str)))
            cout<<str<<endl;
        else cout<<"No Successor\n";
    }
    return 0;
}
