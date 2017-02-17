
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	double a,b,d,l;
	double pi = 2*acos(0.0);
	scanf("%d",&t);
	while(t--){
		scanf("%lf %lf",&d,&l);
		b = l/2.0;
		a = ((b*b) - d*d/4.0);
		a = sqrt(a);
		printf("%.3lf\n",a*b*pi);
	}
	return 0;
}
