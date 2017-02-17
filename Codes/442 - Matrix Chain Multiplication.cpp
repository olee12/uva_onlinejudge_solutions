#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
typedef struct
{
    int row;
    int col;

} MATRIX;
MATRIX matrix[100];
MATRIX res;
int sum;
int mat(string line)
{
    char a,b;
    // cout<<line;
    int z=26;
    sum=0;
    stack<char > s;
    for(int i = 0; i<line.size(); i++)
    {
        if(line[i]=='(') s.push(line[i]);
        else if(line[i]>='A' && line[i]<='Z') s.push(line[i]);
        else
        {
            while(s.top()!='(' && !s.empty())
            {
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                // cout<<a<<endl;
                if(matrix[a-'A'].col == matrix[b-'A'].row)
                {
                    // printf("A row : %d\nA col: %d\nB row : %d\nB col: %d\n",matrix[a-'A'].row,matrix[a-'A'].col,matrix[b-'A'].row,matrix[b-'A'].col);

                    sum += (matrix[a-'A'].row * matrix[b-'A'].col * matrix[a-'A'].col);
                    matrix[z].row=matrix[a-'A'].row;
                    matrix[z].col=matrix[b-'A'].col;

                    // cout<<sum<<endl;


                }
                else
                {
                    return 0;
                }

            }
            if(s.top()=='(') s.pop();
            s.push('A'+z);
            z++;


        }
    }
    return 1;
}
int main()
{
    // cout<<int(26-'A');
    int num;
    int row,col;
    char ch;
    scanf("%d",&num);
    for(int i = 0; i<num; i++)
    {
        scanf(" %c %d %d",&ch,&row,&col);
        //printf("%d\n",ch-'A');
        matrix[ch-'A'].row=row;
        matrix[ch-'A'].col = col;
    }
   /* for(int i = 0; i<num; i++)
    {
        cout<<char('A'+i)<<' '<<matrix[i].row<<' '<<matrix[i].col<<endl;
    }*/
    string line;
    char a ,b;

    while(cin>>line)
    {
        if(mat(line))
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<"error\n";
        }
    }
    return 0;

}
