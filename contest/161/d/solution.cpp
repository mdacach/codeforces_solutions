//
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 60005, MAXE = 2 * MAXN;

int N, K, eadj[MAXE], elen[MAXE], enext[MAXE], elast[MAXN];
int front, back, q[MAXN], V = 0, vis[MAXN], dist[MAXN], size[MAXN], dlist[MAXN];
bool erase[MAXE];

void addedge(int ind, int a, int b, int len)
{
    eadj[ind] = b; elen[ind] = len; enext[ind] = elast[a]; elast[a] = ind;
}

int bfs(int start, bool make = false)
{
    front = back = 0; q[back++] = start;
    vis[start] = ++V; dist[start] = 0;

    while (front < back)
    {
        int top = q[front++];

        for (int i = elast[top]; i != -1; i = enext[i])
            if (!erase[i] && vis[eadj[i]] != V)
            {
                vis[eadj[i]] = V;
                dist[eadj[i]] = dist[top] + elen[i];
                q[back++] = eadj[i];
            }
    }

    for (int i = back - 1; i >= 0; i--)
    {
        size[q[i]] = 1;

        for (int j = elast[q[i]]; j != -1; j = enext[j])
            if (!erase[j] && dist[eadj[j]] > dist[q[i]])
                size[q[i]] += size[eadj[j]];
    }

    if (make)
    {
        for (int i = 0; i < back; i++)
            dlist[i] = dist[q[i]];

        sort(dlist, dlist + back);
    }

    return back;
}

int center(int start)
{
    bfs(start);
    int pos, most = start;

    do
    {
        pos = most;
        most = -1;

        for (int i = elast[pos]; i != -1 && most == -1; i = enext[i])
            if (!erase[i] && size[eadj[i]] < size[pos] && 2 * size[eadj[i]] > size[start])
                most = eadj[i];
    }
    while (most != -1);

    return pos;
}

int pairs(int start, int k = K)
{
    int n = bfs(start, true), total = 0;

    for (int i = 0, j = n - 1; i < j; i++)
    {
        while (j > i && dlist[i] + dlist[j] > k)
            j--;

        total += j - i;
    }

    return total;
}

int solve(int start)
{
    int total = 0;

    for (int i = elast[start]; i != -1; i = enext[i])
        if (!erase[i])
        {
            erase[i ^ 1] = true;
            total -= pairs(eadj[i], K - 2 * elen[i]);
        }

    total += pairs(start);

    for (int i = elast[start]; i != -1; i = enext[i])
        if (!erase[i])
            total += solve(center(eadj[i]));

    return total;
}

int main()
{
    memset(elast, -1, sizeof(elast));
    scanf("%d %d", &N, &K);

    for (int i = 1, e = 0, a, b, len; i < N; i++)
    {
        scanf("%d %d", &a, &b); a--; b--;
        len = 1;
        addedge(e++, a, b, len);
        addedge(e++, b, a, len);
    }

    int answer_K = solve(center(0));
    K--;
    memset(erase, false, sizeof(erase));
    int answer_K1 = solve(center(0));
    printf("%d\n", answer_K - answer_K1);
    return 0;
}
//
