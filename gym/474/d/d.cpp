#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

std::vector<int> ways_ending_with_red(N);
std::vector<int> ways_ending_with_white(N);
std::vector<int> accumulated_sum(N);

void solve()
{
    int a, b;
    std::cin >> a >> b;
    int ans = accumulated_sum[b];
    ans -= (accumulated_sum[a-1]);
    if (ans < 0) ans += MOD;
    std::cout << ans << "\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    int k;
    std::cin >> k;

    for (int i = 1; i <= k; i++)
    {
        ways_ending_with_red[i] = 1;
    }
    ways_ending_with_white[k] = 1;
    for (int i = k+1; i < N; i++)
    {
        ways_ending_with_red[i] = ways_ending_with_red[i - 1] + ways_ending_with_white[i - 1];
        ways_ending_with_white[i] =
            (ways_ending_with_red[i - k] + ways_ending_with_white[i - k]);
        ways_ending_with_red[i] %= MOD;
        ways_ending_with_white[i] %= MOD;
    }

    for (int i = 1; i < N; i++)
    {
        accumulated_sum[i] = accumulated_sum[i-1] + (ways_ending_with_white[i] + ways_ending_with_red[i]) % MOD;
        accumulated_sum[i] %= MOD;
    }

    while (t--)
        solve();

    return 0;
}
