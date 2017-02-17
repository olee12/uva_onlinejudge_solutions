#include<iostream>
#include<stack>
#include<vector>
#include<cstdio>
using namespace std;
char infix[64];
stack<char>stak;
vector<char>postfix;
int main()
{
    int t , ind ,a ,b,s;
    char oper,ref;
    scanf("%d\n",&t);
    getchar();
    getchar();
    while(t--)
    {
      ind = 0;
      while(scanf("%c",&oper)==1 && oper!='\n'&&oper!=EOF)
      {
          getchar();
          infix[ind++] = oper;
      }
          stak.push('(');
          infix[ind] = ')';
          for(a=0;a<=ind;a++)
          {
              if(infix[a]>='0'&&infix[a]<='9')
              postfix.push_back(infix[a]);
              else if(infix[a]=='(')
              stak.push(infix[a]);
              else if(infix[a]=='*'||infix[a]=='/')
              {
                  while(!stak.empty()&&(stak.top()=='*'||stak.top()=='/'))
                  {
                      ref = stak.top();
                      postfix.push_back(ref);
                      stak.pop();
                  }
                  stak.push(infix[a]);
              }
              else if(infix[a]=='-'||infix[a]=='+')
              {
                  while(!stak.empty()&&(stak.top()=='*'||stak.top()=='/'||stak.top()=='-'||stak.top()=='+'))
                  {
                      ref = stak.top();
                      postfix.push_back(ref);
                      stak.pop();
                  }
                  stak.push(infix[a]);
              }
              else
              {
                  while(!stak.empty()&&stak.top()!='(')
                  {
                      ref = stak.top();
                      postfix.push_back(ref);
                      stak.pop();
                  }
                  if(!stak.empty())
                  stak.pop();
              }
          }
          s = postfix.size();
          for(a=0;a<s;a++)
          printf("%c",postfix[a]);
          printf("\n");
          if(t!=0)
          printf("\n");
          postfix.clear();
          while(!stak.empty())
          stak.pop();
    }
    return 0;
}
