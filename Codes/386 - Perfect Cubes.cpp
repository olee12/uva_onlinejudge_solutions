#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int ac,bc,cc,dc;
    register int i,j,k,l;
    for(i=1;i<201;i++){
        ac=i*i*i;
        for(j=2;j<201;j++){
            bc=j*j*j;
            if(bc>=ac) break;
            for(k=j;k<201;k++){
                cc=k*k*k;
                if(bc+cc>=ac) break;
                for(l=k;l<201;l++){
                    dc=l*l*l;
                    if(bc+cc+dc>ac) break;
                    else if((bc+cc+dc)==ac) printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                }
            }
        }
    }
    return 0;
}
