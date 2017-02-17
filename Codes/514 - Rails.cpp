#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    int car[1050];
    int i,j,k,l,pos;

    while(scanf("%d",&n)  && n){
        while(scanf("%d",&car[1]) && car[1]){

            for(i=2;i<=n;i++){
                scanf("%d",&car[i]);
            }
            pos=1;
            stack<int> s;
            for(i=1;i<=n;i++){
                if(car[pos]==i){
                    pos++;
                }
                else s.push(i);

                while(!s.empty() && car[pos]==s.top()){
                    pos++;
                    s.pop();
                }
            }
            if(s.empty()) printf("Yes\n");
            else printf("No\n");
            //while(!s.empty()) s.pop();
        }
        printf("\n");

    }
    return 0;
}
/* RT: .082
#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{

    int n;
    int car[1050];
    int i,j,k,l,pos;
    int st[1050];
    while(scanf("%d",&n)  && n){
        while(scanf("%d",&car[1]) && car[1]){

            for(i=2;i<=n;i++){
                scanf("%d",&car[i]);
            }
            pos=1;


            int top=-1;
            for(i=1;i<=n;i++){
                if(car[pos]==i){
                    pos++;
                }
                else st[++top]=i;

                while(top!=-1 && car[pos]==st[top]){
                    pos++;
                    top--;
                    //cout<<top<<endl;
                }
            }
            if(top==-1) printf("Yes\n");
            else printf("No\n");
            //while(!s.empty()) s.pop();
        }
        printf("\n");

    }
    return 0;
}
*/
