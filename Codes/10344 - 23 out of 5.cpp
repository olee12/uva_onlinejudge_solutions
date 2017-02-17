#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int ara[6];
bool flag;
bool func(int n,int val)
{
    if(n==5)
    {
        if(val==23) return true;
        return false;
    }
    return func(n+1,val + ara[n])||func(n+1,val - ara[n]) || func(n+1,val * ara[n]);
}
int main()
{
    while(scanf("%d %d %d %d %d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4]))
    {
        if(ara[0]==0&&ara[1]==0&&ara[2]==0&&ara[3]==0&&ara[4]==0) return 0;
        flag = false;
        sort(ara,ara+5);
        do
        {
            if(func(1,ara[0]))
            {
                flag = true;
                break;
            }

        }
        while(next_permutation(ara,ara+5));
        if(flag) printf("Possible\n");
        else printf("Impossible\n");
    }

}
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int ara[6];
bool flag;
bool taken[6];
vector<int> result;
bool sum(int i,int val)
{
    if(i==5)
    {
        if(val == 23) return true;
        return false;
    }
    return sum(i+1,val + result[i]) || sum(i+1,val - result[i]) || sum(i+1,val * result[i]);
}
bool tmp;
void pur()
{
    if(flag) return;
    if(result.size()==5)
    {
       tmp =  sum(1,result[0]);
       if(tmp) flag=true;
       return;
    }
    for(int i = 0; i<5; i++)
    {
        if(!taken[i])
        {
            taken[i]=true;
            result.push_back(ara[i]);
            pur();
            taken[i]=false;
            result.pop_back();

        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    while(scanf("%d %d %d %d %d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4]))
    {
        if(ara[0]==0&&ara[1]==0&&ara[2]==0&&ara[3]==0&&ara[4]==0) return 0;
        flag = false;
        tmp = false;
        result.clear();
        pur();
        if(flag) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}

/*#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int ara[6];
int& a = ara[0];
int& b = ara[1];
int& c = ara[2];
int& d = ara[3];
int& e = ara[4];
char str[5]="+-*";
int i ,j,k,l,m,w,x,y,z;
bool func()
{
    for(i = 0; i<5; i++)
    {
        for(j = 0; j<5; j++)
        {
            for(k = 0; k<5; k++)
            {
                for(l = 0; l<5; l++)
                {
                    for(m = 0; m<5; m++)
                    {
                        for(w = 0; w<3; w++)
                            for(x=0; x<3; x++)
                                for(y = 0; y<3; y++)
                                    for(z=0; z<3; z++)
                                    {
                                        int sum = 0;
                                        if(str[w]=='+') sum = ara[i]+ara[j];
                                        else if(str[w]=='-') sum = ara[i]-ara[j];
                                        else if(str[w]=='*') sum = ara[i]*ara[j];

                                        if(str[x]=='+') sum = sum+ara[k];
                                        else if(str[x]=='-') sum = sum-ara[k];
                                        else if(str[x]=='*') sum = sum*ara[k];

                                        if(str[y]=='+') sum = sum+ara[l];
                                        else if(str[y]=='-') sum = sum-ara[l];
                                        else if(str[y]=='*') sum = sum*ara[l];


                                        if(str[z]=='+') sum = sum+ara[m];
                                        else if(str[z]=='-') sum = sum-ara[m];
                                        else if(str[z]=='*') sum = sum*ara[m];
//cout<<sum<<endl;
                                        if(sum == 23) return true;
                                        //if(sum==-23) return true;

                                    }
                    }
                }
            }
        }
    }
    return false;
}
int main()
{


    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)!=EOF)
    {
        if(a==0&&b==0&&c==0&&d==0&&e==0) return 0;

        if(func()) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}

*/
