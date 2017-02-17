#include<bits/stdc++.h>
using namespace std;

long long power(int i,int j)
{
    long long val = 1;
    for(int k = 1; k<=j; k++) val*=i;
    return val;
}
long long tenbase(string str)
{
    int from = 16;
    long long val = 0;
    int len = str.size();
    int eq=0;
    for(int i = len - 1; i>=0; i--)
    {
        if(isdigit(str[i])) eq = str[i]-48;
        else eq = str[i]-55;
        val += (eq*power(from,len - 1- i));
    }
    return val;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    map<char ,string > mp;
    mp['0']="0000";
    mp['1']="0001";
    mp['2']="0010";
    mp['3']="0011";
    mp['4']="0100";
    mp['5']="0101";
    mp['6']="0110";
    mp['7']="0111";
    mp['8']="1000";
    mp['9']="1001";
    mp['A']="1010";
    mp['B']="1011";
    mp['C']="1100";
    mp['D']="1101";
    mp['E']="1110";
    mp['F']="1111";
    char str1[20],str2[20];
    int test;
    scanf("%d",&test);
    cin.ignore();
    char  ch ;
    while(test--)
    {
        scanf("%s %c %s",str1,&ch,str2);

        int len = strlen(str1);
        printf("0");
        if(len == 1) printf("00000000");
        if(len == 2) printf("0000");
        for(int i = 0; str1[i]; i++) cout<<mp[str1[i]];

        // printf(" %c 336",ch);
        printf(" %c ",ch);
        len = strlen(str2);
        printf("0");
        if(len == 1) printf("00000000");
        if(len == 2) printf("0000");
        for(int i = 0; str2[i]; i++) cout<<mp[str2[i]];
        long long res1 = tenbase(str1);
        long long res2 = tenbase(str2);
        if(ch=='+') printf(" = %lld\n",res1+res2);

        else printf(" = %lld\n",res1-res2);

    }
    return 0;

}
