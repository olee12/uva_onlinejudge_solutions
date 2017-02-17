#include<cctype>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define MAX 25
using namespace std;
char str[MAX];
int len;


char letters[] = "A...3..HIL.JM.O...2TUVWXY5";

char digits[] = "1SE.Z..8.";

bool is_mirror()
{
    char ch;
    int pos;
    for(int i = 0,j=len-1;i<=j;i++,j--){
        if(isupper(str[i])){
            pos = str[i]-'A';
            ch = letters[pos];
        }
        else {
            pos = str[i]-'1';
            ch = digits[pos];
        }
        if(str[j]!=ch) return false;
    }
    return true;
}



bool is_plain()
{
    for(int i = 0, j = len - 1; i<j;i++,j--)
        if(str[i]!=str[j]) return false;
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
    #endif // olee
    while(scanf("%s",str)==1){
        len = strlen(str);
        int m = is_mirror();
        int p = is_plain();
        printf("%s",str);
        if(m && p ) printf(" -- is a mirrored palindrome.\n");
        else if(p) printf(" -- is a regular palindrome.\n");
        else if(m) printf(" -- is a mirrored string.\n");
        else printf(" -- is not a palindrome.\n");
        puts("");
    }
    return 0;

}
