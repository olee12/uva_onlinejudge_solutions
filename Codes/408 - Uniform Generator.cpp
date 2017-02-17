#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{


    int a,b;
    while(scanf("%d %d",&a,&b)==2)
        printf("%10d%10d    %s Choice\n\n",a,b,(__gcd(a,b)==1)?"Good":"Bad");
    return 0;

}





























/*
seed(i+1) = (seed(i)+step)%mod
let seed(0) = 0
then we want to prove that
{0*step,1*step,2*step,….,(mod-1)*step} is a permutation of {1,2,3,4,5,6…,mod-1}
This is correct iff gcd(step,mod)=1 i.e they don’t share any prime factors
Proof:
lets start with
A = {1,2,3,4,5,6…,mod-1} multiply by n
X = {1*n,2*n,3*n,…(mod-1)*n}
to prove that X is a permutation of A lets assume A[i]*n = A[j]*n (mod mod) for some i and j
since n is relatively prime to mod then we can cancel it from both sides
then A[i]=A[j] (mod mod) which is only true if i = j
then X is a permutation of A
*/
