//
//
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int mat[1000][1000];
int dist[1000][1000];
int val[1000][1000];
bool visited[1000][1000];
int n;

int dijkstra()
{
    dist[0][0] = val[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i + j == 0)
                continue;

            dist[i][j] = 0x3f3f3f3f;
            if (i > 0)
                dist[i][j] = min(dist[i][j], dist[i - 1][j] + val[i][j]);
            if (j > 0)
                dist[i][j] = min(dist[i][j], dist[i][j - 1] + val[i][j]);
        }

    return dist[n - 1][n - 1];
}

string compute(int ret)
{
    string ans;
    int pi = n - 1, pj = n - 1;
    int tret = ret;
    while (pi != 0 || pj != 0)
    {
        tret -= val[pi][pj];
        if (pi > 0 && dist[pi - 1][pj] == tret)
        {
            ans += "D";
            pi--;
        }
        else
        {
            assert(dist[pi][pj - 1] == tret);
            ans += "R";
            pj--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    scanf("%d", &n);
    int zx = -1, zy = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
            val[i][j] = 0;
            if (mat[i][j] == 0)
            {
                zx = i;
                zy = j;
                val[i][j] = 1;
            }
            else
                for (int tmp = mat[i][j]; tmp % 2 == 0; val[i][j]++, tmp /= 2)
                    ;
        }

    int ret = dijkstra();
    string ans = compute(ret);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            val[i][j] = 0;
            if (mat[i][j] == 0)
                val[i][j] = 1;
            else
                for (int tmp = mat[i][j]; tmp % 5 == 0; val[i][j]++, tmp /= 5)
                    ;
        }

    int ret2 = dijkstra();
    if (ret2 < ret)
    {
        ret = ret2;
        ans = compute(ret2);
    }

    if (zx >= 0 && ret > 1)
    {
        ans = "";
        for (int i = 0; i < zx; i++)
            ans += "D";
        for (int i = 0; i < zy; i++)
            ans += "R";
        for (int i = zx; i < n - 1; i++)
            ans += "D";
        for (int i = zy; i < n - 1; i++)
            ans += "R";
        ret = 1;
    }

//    std::cout << ret << "\n";
    printf("%d\n%s\n", ret, ans.c_str());
}
