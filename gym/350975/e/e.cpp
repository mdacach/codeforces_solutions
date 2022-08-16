#include <bits/stdc++.h>

const int N = 5e6 + 10;
const int MOD = 998'244'353;

int ways[N];
int divisors[N];

int calls = 0;
int solve(int points)
{
    int sum = 0;
    int accum = 0;
    for (int i = 2; i <= points; i+=2)
    {
        accum += sum;
        accum %= MOD;
        sum = accum + divisors[i/2];
        sum %= MOD;
    }
    return sum;
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisors[j]++;
            divisors[j] %= MOD;
        }
    }

    int n;
    std::cin >> n;
    std::cout << solve(2 * n) << "\n";

    return 0;
}
