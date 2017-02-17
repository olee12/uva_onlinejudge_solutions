/*nr_digits[i]    number of digits  value
-----------------------------------------------
9               1                 1 -        9
189             2                10 -       99
2889            3               100 -      999
38889           4              1000 -     9999
488889          5             10000 -    99999
5888889         6            100000 -   999999
68888889        7           1000000 -  9999999
788888889       8          10000000 - 99999999

N = 10000

10000 - 2889 = 7111
(7111 + 3) / 4 = 1778
(1000 - 1) + 1778 = 2777
7111 % 4 = 3    -> 3rd digit of 2777 --> 7

N = 50000

50000 - 38889 = 11111
(11111 + 4) / 5 = 2223
(10000 - 1) + 2223 = 12222
11111 % 5 = 1   -> 1st digit of 12222 --> 1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
   long long  int numdig[11]= {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
   long long int range[11]= {0,9,189,2889,38889,488889,5888889,68888889,788888889,8888888889,98888888889};
    int N;
    int i;
    while(cin>>N)
    {
        i=1;
        while (i <= 11 && N > range[i])
            i++;
       // cout<<i<<endl;;
        long long j = N - range[i - 1];
       // cout<<j<<endl;
       // cout<<(j + i - 1) / i<<endl;
        long long m = (long long)(numdig[i] - 1) + (j + i - 1) / i;
       // cout<<m<<endl;
        if(j%i)
        {
            for(int k =i - (j%i); k; k--)
            {
                m/=10;
            }

        }
        cout<<m%10<<endl;
    }
    return 0;
}
