#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{

    char n1[30],n2[30];
    int i,l1,l2,t1,t2,v1,v2;
    float j;

    while(gets(n1))
    {
        gets(n2);
        l1 = strlen(n1);
        l2 = strlen(n2);
        t1=0;
        for(i=0; i<l1; i++)
        {
            if(n1[i]>='a'&&n1[i]<='z')
                t1+=n1[i]-96;
            else if(n1[i]>='A'&&n1[i]<='Z')
                t1+=n1[i]-64;
        }
        v1=0;
        while(t1!=0)
        {
            v1+=t1%10;
            t1/=10;
        }
        if(v1>9)
        {
            t1=v1;
            v1=0;
            while(t1!=0)
            {
                v1+=t1%10;
                t1/=10;
            }
        }
        printf("%d\n",v1);

        t2=0;

        for(i=0; i<l2; i++)
        {
            if(n2[i]>='a'&& n2[i]<='z')
                t2+=n2[i]-96;
            else if(n2[i]>='A'&&n2[i]<='z')
                t2+=n2[i]-64;
        }
        v2=0;
        while(t2!=0)
        {
            v2+=t2%10;
            t2/=10;
        }
        if(v2>9)
        {
            t2 = v2;
            v2 = 0;
            while(t2!=0)
            {
                v2+=t2%10;
                t2/=10;
            }
        }
        printf("%d\n",v2);

        if(v1>v2)
            j = (float)v2*100/(float)v1;

        else
            j = (float)v1*100/(float)v2;
        printf("%0.2f %%\n",j);


    }


}
