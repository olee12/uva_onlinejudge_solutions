#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int fro[500],rear[500];
int main()
{
    //freopen("input.txt","r",stdin);
    int f,r;
    while(scanf("%d",&f)&&f)
    {
        scanf("%d",&r);
        for(int i= 0;i<f;i++) scanf("%d",&fro[i]);
        for(int i= 0;i<r;i++) scanf("%d",&rear[i]);
        vector<double> v;
        for(int i = 0;i<r;i++)
        {
            for(int j = 0;j<f;j++)
            {
                double t =(double)rear[i]/(double)fro[j];
                v.push_back(t);
            }
        }
        sort(v.begin(),v.end());

        double res = 0;
        vector<double>::iterator it;
        for(it = v.begin() + 1; it < v.end(); ++it)
        {
            double tmp = *it / *(it - 1);
             if(tmp > res) res = tmp;
        }
        printf("%.2lf\n",res);
    }
    return 0;

}
