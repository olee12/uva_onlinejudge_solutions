#include<stdio.h>
#include<string.h>
int main()
{
    char ch[50];
    int i,l;
    while(scanf("%s",&ch)==1)
    {
        l = strlen(ch);
        for(i=0; i<l; i++)
        {
            if((ch[i] == 'A')|| (ch[i]=='B')||(ch[i]=='C'))
                printf("2");
            else if((ch[i] == 'D')|| (ch[i]=='E')||(ch[i]=='F'))
                printf("3");
            else if((ch[i] == 'G')|| (ch[i]=='H')||(ch[i]=='I'))
                printf("4");
            else if((ch[i] == 'J')|| (ch[i]=='K')||(ch[i]=='L'))
                printf("5");
            else if((ch[i] == 'M')|| (ch[i]=='N')||(ch[i]=='O'))
                printf("6");
            else if((ch[i] == 'P')|| (ch[i]=='Q')||(ch[i]=='R')||(ch[i]=='S'))
                printf("7");
            else if((ch[i] == 'T')|| (ch[i]=='U')||(ch[i]=='V'))
                printf("8");
            else if((ch[i] == 'W')|| (ch[i]=='X')||(ch[i]=='Y')||(ch[i]=='Z'))
                printf("9");
            else
                printf("%c",ch[i]);
        }
        printf("\n");
    }
    return 0;
}



//#include<stdio.h>
//
//
//#include<string.h>
//
//
//int main()
//
//
//{
//
//
//    char s[50],l;
//
//
//    int i,j;
//
//
//    while(scanf("%s",&s)==1)
//
//
//    {
//
//
//        l=strlen(s);
//
//
//        for(i=0; i<l; i++)
//
//
//        {
//
//
//            if((s[i]=='A')||(s[i]=='B')||(s[i]=='C'))
//
//
//                printf("2");
//
//
//            else if((s[i]=='D')||(s[i]=='E')||(s[i]=='F'))
//
//
//                printf("3");
//
//
//            else if((s[i]=='G')||(s[i]=='H')||(s[i]=='I'))
//
//
//                printf("4");
//
//
//            else if((s[i]=='J')||(s[i]=='K')||(s[i]=='L'))
//
//
//                printf("5");
//
//            else if((s[i]=='M')||(s[i]=='N')||(s[i]=='O'))
//
//
//                printf("6");
//
//
//            else if((s[i]=='P')||(s[i]=='Q')||(s[i]=='R')||(s[i]=='S'))
//
//
//                printf("7");
//
//
//            else if((s[i]=='T')||(s[i]=='U')||(s[i]=='V'))
//
//
//                printf("8");
//
//
//            else if((s[i]=='W')||(s[i]=='X')||(s[i]=='Y')||(s[i]=='Z'))
//
//
//                printf("9");
//
//
//            else
//
//
//                printf("%c",s[i]);
//
//
//        }
//
//
//        printf("\n");
//
//
//    }
//
//
//
//
//
//    return 0;
//
//
//}

