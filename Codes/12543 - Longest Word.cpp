#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char str[120];
    char ara[120];
    string big;
    int i,j,k,l;
    int maxi=0;
    while(scanf("%s",str)){
            j=0;
            if(strcmp(str,"E-N-D")==0) break;
        for(i = 0;str[i];i++){
            if(isalpha(str[i]) || str[i]=='-'){
                ara[j++]=tolower(str[i]);
            }
            else {
                j=0;
            }
            ara[j]='\0';
            if(maxi<j) {maxi = j;
            big = string(ara);
            }
        }
    }
    cout<<big<<endl;
    return 0;

}
