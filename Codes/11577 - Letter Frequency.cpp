#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<cctype>
using namespace std;
int flag[200];
int main()
{

    char text[500];

    int t,l,j,k=0;
    scanf("%d\n",&t);
    {

        while(t--)
        {


            gets(text);
            l=strlen(text);
            k=0;
            for(int i=0; i<l; i++)
            {
                text[i]=tolower(text[i]);
            }
            for(int i=0; i<l; i++)
            {
                if(isalpha(text[i]))
                {
                    flag[text[i]]++;

                }
            }

            for(int i = 97; i<=122; i++)
            {
                if(k<flag[i])
                {
                    k=flag[i];
                }
            }
            for(int i=97; i<=122; i++)
            {
                if(flag[i]==k)
                {
                    printf("%c",i);
                }
                flag[i]=0;
            }
            printf("\n");
        }
    }
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<cstdlib>
using namespace std;
int comp(const void *a,const void *b);
int main()
{
    int test;
    int relative;
    int street[30005];
    int total;
    int i,j;
    int mid;
    scanf("%d",&test);

        while(test--)
        {
            mid=0;
            scanf("%d",&relative);
            total=0;
            for(i=0; i<relative; i++) scanf("%d",&street[i]);
            qsort(street,relative,sizeof (int), comp);

            j=relative>>1;
            if(j==0) mid = (street[j]+street[j-1])/2;
            else mid = street[j];
            for(i=0;i<relative;i++) total+=abs(mid-street[i]);
            printf("%d\n",total);

        }

    return 0;
}
int comp(const void *a,const void *b)
{
    return(*(int *)a-*(int *)b);
}
*/
