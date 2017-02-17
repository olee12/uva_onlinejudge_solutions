#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char graph[55][55];
int row ,col;
int cnt;
int x[]= {0,0,-1,1};
int y[]= {-1,1,0,0};
bool isvalid(int x,int y)
{
    return (x>=0 && x<row && y >= 0 && y<col);
}

void dfs2(int i,int j)
{
    graph[i][j]='*';
    int tx,ty;
    for(int k = 0; k<4; k++)
    {
        tx = i + x[k];
        ty = j + y[k];
        if(isvalid(tx,ty))
            if(graph[tx][ty]=='X')
                dfs2(tx,ty);
    }
}


void dfs1(int i, int j)
{

    if(graph[i][j]=='X')
    {

        cnt++;

        dfs2(i,j);
    }
    // cout<<"in\n";
    graph[i][j]='.';
    int tx;
    int ty ;
    for(int k = 0; k<4; k++)
    {
        tx = i + x[k];
        ty = j + y[k];
        if(isvalid(tx,ty))
        {
            if(graph[tx][ty]!='.') dfs1(tx,ty);
        }
    }


}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE

    int cas=1;
    while( scanf("%d %d ",&col,&row))
    {
        if(row==0 && col==0) break;

        // cout<<row<<' '<<col<<endl;
        for(int i = 0; i<row; i++)
        {
            scanf("%s",graph[i]);
            //puts(graph[i]);
        }

        vector<int> v;
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(graph[i][j]!='.')
                {

                    cnt=0;
                    dfs1(i,j);
                    //cout<< "in: "<<cnt<<endl;
                    v.push_back(cnt);
                }
            }

        }
        sort(v.begin(),v.end());
        printf("Throw %d\n",cas++);
        for(int i = 0; i<v.size(); i++)
        {
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n\n");

        // break;
    }
    return 0;

}

