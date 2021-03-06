
#include <stdio.h>
#include <math.h>
#include <string.h>

/* 10515 - Powers Et Al.
 Each line contains two integers m and n (Less than 10^101). find the last digit of m^n
 Sample Input
 2 2
 2 5
 0 0
 Output for Sample Input
 4
 2
 http://mathcentral.uregina.ca/QQ/database/QQ.09.04/landon1.html
 http://khvmathematics.blogspot.com/2008/01/how-to-find-last-digit-of-any-number.html
(1) Divide n by 4
(2) If the remainder is r, then the last digit is ((m%10)^r)%10.
(3) if the remainder is zero, set r=4 and do (2).
*/
/*
int main() {

    char m[150], n[150];
    int r, lastdigit;
    int size_m, size_n;

    while (scanf("%s %s", m, n) == 2) {

        size_m = (int) strlen(m);
        size_n = (int) strlen(n);

        if (m[size_m-1]=='0' && m[size_n-1]=='0' && size_m == 1 && size_n == 1)
           break;

        // a number%4 can be done by taking the (last 2 digits%4)
        r = n[size_n-1]-'0';

        if (size_n > 1)
            r += (n[size_n-2]-'0')*10;

        r = r%4;

        if (r == 0)
            r = 4;

        lastdigit = (int)(pow((m[size_m-1]-'0'), r));
        printf("%d\n", lastdigit%10);
    }
    return 0;
}*/
/*METHOD: To find the last digit of number mn Divide n by 4,
 If the remainder is r, then the last digit of the number is (the last digit of given number)^r.
 otherwise if remainder is zero, then the last digit of number is last digit of m^4*/

#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    char m[150],n[150];
    int r,f;
    int m_size,n_size;
    while(scanf("%s %s",m,n)==2)
    {

        m_size=strlen(m);
        n_size=strlen(n);
        if (m[m_size-1]=='0' && m[m_size-1]=='0' && n_size == 1 && m_size == 1)
            break;

        r = n[n_size-1]-'0';
        if(n_size>1) r +=(n[n_size-2]-'0')*10;
        cout<<r<<endl;
        r=r%4;
        if(!r) r=4;
        f=(int)(pow((m[m_size-1]-'0'), r))%10;
       printf("%d\n",f);
    }
    return 0;
}
