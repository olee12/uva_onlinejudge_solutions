
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int n,b,h,w;
  while(scanf("%d %d %d %d",&n,&b,&h,&w)==4){
  	int res = -1;
  	int mn =1e8;
  	for(int i = 0;i<h;i++){
  		int p;
  		scanf("%d",&p);
  		for(int j = 0;j<w;j++){
  			int a;
  			scanf("%d",&a);
  			int flag = p*n;
  			if(a>=n && flag <= b){
  				res = flag;
  				if(res < mn){
  					mn = res;
  				}
  			}
  		}
  	}
  	if(res!=-1){
  		printf("%d\n",mn);
  	}
  	else printf("stay home\n");
  }
	return 0;
}
