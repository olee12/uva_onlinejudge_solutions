/*#include<stdio.h>
#include<math.h>
int main()
{
    char ara[5];
    int n,i,j=0,k,l;
    while(scanf("%d",&k)==1)
    {
        while(k--)
        {
            scanf("%3s-%d", ara, &n);

            j = (ara[2]-'A')*(int) pow(26,0) + (ara[1]-'A')*(int) pow(26,1) + (ara[0]-'A')*(int) pow(26,2);

            if(abs(j-n) <= 100) printf("nice\n");
            else printf("not nice\n");
        }

    }
    return 0;
}*/

#include<stdio.h>
#include<math.h>


int lval(char l[]) {
    printf("%d\n",26 * 26 * (l[0] - 'A') + 26 * (l[1] - 'A') + (l[2] - 'A'));
	return 26 * 26 * (l[0] - 'A') + 26 * (l[1] - 'A') + (l[2] - 'A');
}


int main() {
	char lll[4];
	int tc, d;


	scanf("%d", &tc);
	while (tc--) {
		scanf("%3s-%d", lll, &d);
		if (abs(lval(lll) - d) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}


	return 0;
}

