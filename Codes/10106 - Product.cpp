#include<string.h>
#include<stdio.h>

void rev(char ch[], int r[])
{
    int len = strlen(ch)-1;
    for(int i = 0; i<=len; i++)
    {
        r[len-i] = ch[i] - '0';
    }
}

int main()
{
    int i,j,k;
    char first[250], second[250];
    int result[500], firstRev[250], secondRev[250];

    while(scanf("%s",first)+scanf("%s",second)==2)
    {

        for(i=0; i<250; i++)
        {
            firstRev[i] = 0;
            secondRev[i] = 0;
            result[i]  = 0;
        }
        for(; i<500; i++)
        {
            result[i] = 0;
        }

        rev(first, firstRev);
        rev(second, secondRev);


        int firstLen = strlen(first), secondLen = strlen(second);

        for(i = 0; i<secondLen; i++)
        {
            for(j = 0; j<firstLen; j++)
            {
                k = i+j;


                result[k] +=  firstRev[j] * secondRev[i];
                result[k+1] += result[k] / 10;
                result[k] = result[k] % 10;
            }
        }

        for(i=499; i>=0 && !result[i]; i--);
        if(i==-1)
        {
            printf("0");
        }
        for(; i>=0; i--)
        {
            printf("%d", result[i]);
        }
        printf("\n");
    }


    return 0;


}
