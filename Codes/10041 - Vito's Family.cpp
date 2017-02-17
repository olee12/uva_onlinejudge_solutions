#include<iostream>
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
    scanf("%d",&test);

        while(test--)
        {
            scanf("%d",&relative);
            total=0;
            for(int i=0; i<relative; i++) scanf("%d",&street[i]);
            qsort(street,relative,sizeof (int), comp);
            int mid;
            j=relative>>1;
            if(j==0){ mid = (street[j]+street[j-1])/2;}
            else mid = street[j];
            for(i=0;i<relative;i++) total+=abs(mid-street[i]);
            printf("%d\n",total);
          //  cout<<endl;
        }

    return 0;
}
int comp(const void *a,const void *b)
{
    return(*(int *)a-*(int *)b);
}
