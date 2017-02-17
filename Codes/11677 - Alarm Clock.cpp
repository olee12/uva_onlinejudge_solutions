#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int h1,h2,m1,m2;
	while(cin>>h1>>m1>>h2>>m2){
		if(h1==0 && h2==0 && m1 == 0 && m2 == 0) break;
		if(h1==0) {
			cout<<h2*60+(m2-m1)<<endl;
			continue;
		}
		if(h2==0) h2=24;
		if(h1==h2 && m1>m2){
			cout<<24*60+(m2-m1)<<endl;
		}
		else if(h2<h1){
			cout<<(24-h1+h2)*60+(m2-m1)<<endl;
		}
		else
			cout<<(h2-h1)*60+(m2-m1)<<endl;
	}
	return 0;
}