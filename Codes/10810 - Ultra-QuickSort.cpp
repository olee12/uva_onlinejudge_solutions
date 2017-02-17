///trying whith merge sort
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<iterator>
using namespace std;
long long cnt = 0;
template<class T>
void Merge(T *initlist,T *mergedlist,const int l,const int m,const int n)
{
    /// initlist[l:m] and initlist[m+1:n] are sorted list. they are merged to obtain
    /// the sorted list mergedlist[l:n]

    int i1,iresult,i2;
    for(i1 = l,iresult = l,i2 = m+1; /// i1,i2,iresult are list positions
            i1<=m && i2 <=n; ///nither input list is exhausted
            )
    {
        if(initlist[i1]<=initlist[i2])
        {
            mergedlist[iresult++] = initlist[i1];
            i1++;
            cnt += (iresult - i1);
           // cout<<"in : "<<initlist[i1-1]<<' '<<iresult<<' '<<i1<<endl;
        }
        else
        {
            mergedlist[iresult++] = initlist[i2];
          //  cout<<initlist[i2]<<' '<<iresult<<' '<<cnt<<endl;
            i2++;
            //    cnt+= ()
        }

    }
  //  cout<<cnt<<'p'<<iresult<<endl;
    for(int x = i1; x<m+1; x++) mergedlist[iresult++]=initlist[x],cnt += (iresult - x-1);
    for(int x = i2; x<n+1; x++) mergedlist[iresult++]= initlist[x];
      //  cout<<"cnt: "<<cnt<<endl;
}
template<class T>
void Mergepass(T *initlist,T *resultlist,const int n,const int s)
{
    /// adjacent pairs of sublist of size s are merged
    /// from initlist to resultlist, n is the number of record in the list;
    int i;
    for( i = 1; /// i is the first position in first of the sublist being merged
            i<= n- 2*s + 1;/// enough elements for two sublist of length s ?
            i+= 2*s
       )
    {
        Merge(initlist,resultlist,i,i+s-1,i+2*s-1);
    }
    ///merge remaining list of size < 2*s
    if((i+s-1)<n) Merge(initlist,resultlist,i,i+s-1,n);
    else for(int x = i; x<=n; x++) resultlist[x]=initlist[x];



}
template< class T>
void Mergesort(T *a,const int n)
{
    /// sort a[1:n] into nondecreasing order

    T *tmplist = new T[n+1];
    /// l is the length of the sublist currently being merged
    for(int l = 1; l<n; l*=2)
    {
        Mergepass(a,tmplist,n,l);
        l*=2;
        Mergepass(tmplist,a,n,l);
    }

    delete[] tmplist;
}
int main()
{
   int n;
   long long ara[500010];
   while(scanf("%d",&n) && n)
   {
    for(int i = 1;i<=n;i++) scanf("%lld",ara+i);
    cnt=0;
    Mergesort(ara,n);
    printf("%lld\n",cnt);
   }
   return 0;

}
