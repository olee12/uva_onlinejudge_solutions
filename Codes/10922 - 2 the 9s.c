//#include<stdio.h>
//#include<string.h>
//int main()
//{
//    int i,j=0,l,k=0,sum=0,d=0;
//    char s[9000];
//    while(gets(s))
//    {
//        if(s[0]==0 && s[1]=='\0') break;
//        l=strlen(s);
//        for(i=0; i<l; i++)
//        {
//            sum += (s[i]-48);
//        }
//
//        if(sum%9==0)
//        {
//            if(sum!=9)
//                d=1;
//
//
//            while(sum>10)
//            {
//
//                while(sum!=0)
//                {
//                    j=sum%10;
//                    sum/=10;
//                    k += j;
//                }
//                ++d;
//                sum = k;
//                k=0;
//            }
//
//            printf("%s is a multiple of 9 and has 9-degree %d.\n",s,d);
//        }
//        else
//        {
//            printf("%s is not a multiple of 9.\n");
//        }
//        sum = 0;
//
//        j=0;
//        d=0;
//
//    }
//    return 0;
//}
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char ary[9000];
    int sum,i,len,n,a,b,c;
    while(gets(ary))
    {
        if((ary[0]=='0')&&(ary[1]=='\0'))
            break;
        c=0;
        sum=0;
        len=strlen(ary);
        for(i=0; i<len; i++)
            sum=sum+(ary[i]-48);

        if(sum%9==0)
        {
            if(sum!=9)
                c=1;
            do
            {
                n=sum;
                sum=0;

                while(n!=0)
                {
                    a=n%10;
                    b=n/10;
                    n=b;
                    sum=sum+a;
                }
                c=c+1;
            }
            while(sum>10);
            printf("%s is a multiple of 9 and has 9-degree %d.\n",ary,c);
        }
        else
            printf("%s is not a multiple of 9.\n",ary);
    }
    return 0;
}
