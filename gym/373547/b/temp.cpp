#include <iostream>

#define int int64_t

const int N = 10;

int grid[N + 2][N + 2];
int ways[N + 2][N + 2];
int fact[2 * N + 2];

int comb(int a, int b)
{
    if (b == 0) return 1;
    if (a - b < 0)
        return 0;
    int num = fact[a];
    int den1 = fact[b];
    int den2 = fact[a - b];
    return num / den1 / den2;
}

int fexp(int b, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1)
            res *= b;
        b *= b;
        e /= 2;
    }
    return res;
}

int32_t main()
{
    fact[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
        fact[i] = fact[i - 1] * i;

    ways[1][1] = 1;
    for (int x = 1; x < N; ++x)
    {
        for (int y = 1; y < N; ++y)
        {
            ways[x + 1][y] += ways[x][y];
            ways[x][y + 1] += ways[x][y];
        }
    }

    auto& dways = ways;
    for (int x = 1; x < N; ++x)
    {
        for (int y = 1; y < N; ++y)
        {
            int ans = ways[x][y];
            int n = x;
            int k = y - 1;
            int cmb = comb(n - 1 + k, k);
            int different_sums = x * y + 1;
            if (ans != cmb)
                std::cout << "BAD\n";
        }
    }
}
