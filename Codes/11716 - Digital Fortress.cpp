#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    char ara[201][201];
    string str;
    int test;
    cin>>test;
    getchar();
    int row;
    double s;
    while(test--){
            getline(cin,str);
         row = sqrt(str.size());
        s = sqrt(str.size());
        if(row==s){
                int f=0;

            for(int i=0;i<row;i++){
                for(int j=0;j<row;j++){
                        ara[i][j]=str[f];
                        f++;
                }
            }

            for(int i=0;i<row;i++){
                for(int j=0;j<row;j++) cout<<ara[j][i];
            }
            cout<<endl;

        }
        else cout<<"INVALID"<<endl;

    }
    return 0;
}
