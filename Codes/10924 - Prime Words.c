#include <stdio.h>
int main()
{
    int bin;
    char s[50];
    int i,j=0;
    while(gets(s))
    {
        for(i=0; s[i]; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                j+= (s[i]-'a'+1);
            else if(s[i]>='A'&&s[i]<='Z')
                j+= (s[i] - 'A' + 27);
        }

        bin=1;
        for(i=2; i<=j/2; i++)
            if(j%i==0)
            {
                bin=0;
                break;
            }
        if(bin==1)
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
        j=0;
    }

    return 0;
}



//int prime(int n)
//{
//    if(n==1) return 0;
//    int i, root;
//    if(n==2)
//    {
//        return 1;
//    }
//    if(n%2==0)
//    {
//        return 0;
//    }
//    root = sqrt(n);
//    for(i=3; i <= root; i = i + 2)
//   {
//        if(n%i==0)
//        {
//           return 0;
//        }
//   }
//   return 1;
//}
