/*#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<set>
#include<stack>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    string arr;
    char str[100];

    int t,n;
    while(scanf("%d",&t))
    {
        while(t--)
        {
            int ara[11]= {0};
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
            {
                snprintf(str,100,"%d",i);
                for(int j=0; str[j]; j++)
                {
                    switch(str[j])
                    {
                    case '0':
                        ara[0]++;
                        break;
                    case '1':
                        ara[1]++;
                        break;
                    case '2':
                        ara[2]++;
                        break;
                    case '3':
                        ara[3]++;
                        break;
                    case '4':
                        ara[4]++;
                        break;
                    case '5':
                        ara[5]++;
                        break;
                    case '6':
                        ara[6]++;
                        break;
                    case '7':
                        ara[7]++;
                        break;
                    case '8':
                        ara[8]++;
                        break;
                    case '9':
                        ara[9]++;
                        break;
                    }
                }


            }
            for(int i=0; i<10; i++) printf("%d ",ara[i]);
            printf("\n");
        }

    }
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
using namespace std;
int main()
{
    int t,n;

    scanf("%d",&t);
    while(t--){
           map<char ,int > ara;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int j=i;
            while(j>0){
                ara[j%10 +'0']++;
                j/=10;
            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",ara['0'],ara['1'],ara['2'],ara['3'],ara['4'],ara['5'],ara['6'],ara['7'],ara['8'],ara['9']);
    }
    return 0;
}
