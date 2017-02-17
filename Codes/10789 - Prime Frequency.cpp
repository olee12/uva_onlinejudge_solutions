#include<iostream>
#include<cstdio>
#include<string>



using namespace std;

#define MAXX 2001
#define SIZE 168
#define loop(i, n) for(int i=0; i<n; i++)

int primes[SIZE];
bool isPrime[MAXX];



void genaratePrimes()
{
    int p = 0;

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i<MAXX; i++)
    isPrime[i] = true;

    for(int i=2; i<1001; i++)
    {
        if(isPrime[i])
        {
            primes[p++] = i;
            for(int j=2*i; j<MAXX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

}











int main()
{
    genaratePrimes();



    int numbers[10], bigAlphabet[26], smallAlphabet[26];
    int kases, len, kaseno = 0;
    string str;
    bool flag;


    scanf("%d", &kases);
    while(kases--)
    {
        loop(i, 10) numbers[i] = 0;
        loop(i, 26)
        {
            smallAlphabet[i] = 0;
            bigAlphabet[i] = 0;
        }
        flag = false;
        cin>>str;
        len = str.size();
        loop(i, len)
        {
            if('0'<= str[i] && str[i] <= '9')
            {
                numbers[str[i] - '0']++;
            }
            else if('a' <= str[i] && str[i] <= 'z')
            {
                smallAlphabet[str[i]-'a']++;
            }
            else
            {
                bigAlphabet[str[i] - 'A']++;
            }
        }



        printf("Case %d: ", ++kaseno);
        loop(i, 10)
        {
            if(isPrime[numbers[i]])
            {
                flag = true;
                printf("%d", i);
            }
        }
        loop(i, 26)
        {
            if(isPrime[bigAlphabet[i]])
            {
                flag = true;
                printf("%c", i+'A');
            }
        }
        loop(i, 26)
        {
            if(isPrime[smallAlphabet[i]])
            {
                flag = true;
                printf("%c", i+'a');
            }
        }


        if(!flag)
        {
            printf("empty");
        }

        printf("\n");

    }



}

