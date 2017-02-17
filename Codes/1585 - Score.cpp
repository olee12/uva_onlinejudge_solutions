/*#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 100099
double x,y,c;
const double next = 1e-10;
const double ext_pnt =  1e-12;
int main()
{
    char str[100];
    int test;
    scanf("%d",&test);
    int sum,a;
    while(test--)
    {
        sum = 0;
        a = 1;
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0;i<len;i++)
        {
            if(str[i]=='X') {
                a = 1;
            }
            else
            {
                sum+=a;
                a++;
            }
        }
        printf("%d\n",sum);

    }
    return 0;
}
Idea: After three good demand, mod = 1000 is fast power.
The top three how ask? - Logarithmic
So x = lg (n ^ k) of the integer part,
y = lg (n ^ k) the fractional part of the n ^ k determined by the
y - since 1000 ... 10 ^ x is 0. So 10 ^ y and then multiplied by 100 rounding is three.
 */
#include<cstdio>
#include<cmath>
#define sf scanf
#define pf printf
typedef long long ll;
const int mod = 1000;

ll pow_mod(int n, int k)
{
	if (k == 0) return 1;
	ll temp = pow_mod(n, k >> 1);
	temp = temp * temp % mod;
	if (k & 1) temp = temp * n % mod;
	return temp;
}

int main()
{
	int t, n, k;
	double intpart;
	sf("%d", &t);
	while (t--)
	{
		sf("%d%d", &n, &k);
		pf("%d...%03lld\n", (int)pow(10.0, 2.0 + modf((double)k * log10(n), &intpart)), pow_mod(n, k));
	}
	return 0;
}
