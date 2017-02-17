#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
    string str;
    int i,j,k,l,t;
    scanf("%d",&t);
            getchar();
        while(t--){
                stack< char > st;
             getline(cin,str);

             if(str.compare("\n")==0){
                printf("Yes\n");
                continue;
             }
             if(str.size()==1 || (str.size()%2 )!= 0){
                printf("No\n");
                continue;
             }

            k=0;
            for(i=0;i<str.size();i++){
                if(str[i]=='(' || str[i]=='[') {
                    st.push(str[i]);
                   }
                else if(str[i]==')' && !st.empty() && st.top()=='(') st.pop();
                else if(str[i]==']' &&  !st.empty() && st.top()=='[') st.pop();
                else k=1;
            }

            if(st.empty() && k==0) printf("Yes\n");
            else
                printf("No\n");
        }

    return 0;
}
