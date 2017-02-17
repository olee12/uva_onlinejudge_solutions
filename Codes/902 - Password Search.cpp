/*
 * 902 - Password Search
 *
 *  Created on: Mar 17, 2014
 *      Author: Olee
 */
#include <bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
typedef long long ll;
int main(int argc, char **argv)
{
	int n, len,a;
	char ch[1000001];
	string str, tmp;
	ll res ,md;
	map<long long, int> pass;
	int j;
	while (sf("%d %s", &n, ch) != EOF)
	{

		pass.clear();
		len = strlen(ch);
		for (int i = 0; i + n <= len; i++)
		{
			md = 0;
			for(j = 0;j<n;j++)
			{
				md = md*26 + (ch[i+j]-'a');
 			}

			pass[md]++;
		}
		int mx = -1;
		map<long long, int> :: iterator it;
		for (it = pass.begin(); it != pass.end(); it++)
		{
			// cout<<it->fr<<' '<<it->sc<<endl;
			if (it->second > mx)
			{
				res = it->first;
				mx = it->second;
			}

		}
		tmp = "";

		for(int i = 0;i<n;i++)
		{
			tmp =(char) (res%26+'a') + tmp ;

			res/=26;

		}
		pf("%s\n",tmp.c_str());
	}
	return 0;
}
