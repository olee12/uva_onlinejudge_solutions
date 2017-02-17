#include<cstdio>
#include<cstring>
using namespace std;
int ara[15];
int men = 25;
int main()
{
    //#ifndef ONLINE_JUDGE

   // #endif // ONLINE_JUDGE
   // freopen("input.txt","r",stdin);
    int n;
    while(scanf("%d",&n) && n)
    {
        char ch;
        getchar();
        int sp = 0;
        for(int i = 0; i<n;)
        {
            scanf("%c",&ch);
           // printf("%c",ch);
            if(ch=='X') continue;
            else if(ch==' ') sp++;
            else
            {
                ara[i++]=sp;
                if(sp<men) men = sp;
                sp = 0;
            }
        }
        int res= 0;
        for(int i = 0; i<n; i++)
        {
            res += (ara[i]-men);
        }
        printf("%d\n",res);
        men = 25;
    }
    return 0;
}
