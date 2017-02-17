int main()
{
    int i,j;
    scanf("%d",&i);
    for(j=1; j<=i; j++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a<=20 && b<=20 && c<=20)
            printf("Case %d: good\n",j);
        else
            printf("Case %d: bad\n",j);
    }
    return 0;
}
