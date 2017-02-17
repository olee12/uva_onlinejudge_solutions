#include<stdio.h>

int main()
{
    char ch;
    int a=0;


        while((scanf("%c",&ch)==1))
        {

            if(ch >= '0' && ch <='9') a += (ch-'0');

            else {
             if((ch>='A'&&ch<='Z')||ch=='*')


                while(a) printf("%c",ch),a--;



            else if(ch=='b')
            {
                while(a) printf(" "),a--;
            }
            else if(ch == '!') printf("\n");
            else if(ch=='\n') printf("\n");
            a = 0;
            }

        }


    return 0;
}

