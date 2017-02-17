#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int N;
void did()
{
    int flag=0;
    int firstnum,secondnum;
    int valid;
    int a,b;
    int used[10];
    for(firstnum=1234;firstnum<=98765;firstnum++)
    {
        secondnum=firstnum/N;
        if(firstnum%N==0 && secondnum >= 1234
            && !(firstnum<10000 && firstnum/N < 10000))
        {
            for(int i=0;i<10;i++)
            used[i]=0;
            a = firstnum;
            valid=1;
            if(firstnum<10000 || firstnum/N <10000)
                used[0]=1;

            while(a!=0){
                b=a%10;
                if(used[b]){
                    valid=0;
                    break;
                }
                else used[b]=1;
                a/=10;
            }
            if(valid){
                a=firstnum/N;
                while(a!=0){
                b = a%10;
                if(used[b]){
                    valid = 0;
                    break;
                }
                else used[b]=1;
                a/=10;
                }
            }
            b = firstnum/N;
            if(valid){
                flag=1;
                if(firstnum<10000)
                    cout<<"0";
                    cout<<firstnum;
                    cout<<" / ";
                    if(b<10000) cout<<"0";
                    cout<<b;
                    cout<<" = "<<N<<endl;

            }

        }
    }
    if(!flag) printf("There are no solutions for %d.\n",N);
}

int main()
{

    int f=0;
    while(cin>>N && N){
        if(f) puts("");
            f=1;
        did();
    }
    return 0;
}
