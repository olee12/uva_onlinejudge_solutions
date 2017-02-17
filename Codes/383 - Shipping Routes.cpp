#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int T, C = 1;
    scanf("%d", &T);
    puts("SHIPPING ROUTES OUTPUT");
    while (T--)
    {
        puts("");
        printf("DATA SET  %d\n", C++);
        puts("");
        int m, n, p;
        scanf("%d%d%d", &m, &n, &p);
        while (m--)
        {
            char s[20];
            scanf("%s", s);
        }
        map<string, vector<string> > con;
        while (n--)
        {
            char s1[20], s2[20];
            scanf("%s%s", s1, s2);
            con[string(s1)].push_back(string(s2));
            con[string(s2)].push_back(string(s1));
        }
        while (p--)
        {
            int size;
            char s1[20], s2[20];
            scanf("%d%s%s", &size, s1, s2);
            queue<string> q;
            map<string, int> dis;
            q.push(string(s1));
            dis[string(s1)] = 0;
            bool find = 0;
            while (!q.empty())
            {
                string now = q.front();
                int d = dis[now];
                q.pop();
                if (now == string(s2))
                {
                    find = 1;
                    printf("$%d\n", d * size * 100);
                    break;
                }
                int i;
                for (i = 0; i < con[now].size(); i++)
                    if (!dis.count(con[now][i]))
                    {
                        q.push(con[now][i]);
                        dis[con[now][i]] = d + 1;
                    }
            }
            if (!find) puts("NO SHIPMENT POSSIBLE");
        }
    }
    puts("\nEND OF OUTPUT");
    return 0;
}
