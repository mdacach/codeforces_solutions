#include <bits/stdc++.h>

auto solve() -> void
{
    int64_t n, key_cost;
    std::cin >> n >> key_cost;
    std::vector<int64_t> chests(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> chests[i];

    int64_t answer = 0;
    std::vector<int64_t> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + chests[i];
    for (int i = 0; i <= n; ++i)
    {
        int64_t from_good = prefix_sum[i] - i * key_cost;
        int64_t from_bad = 0;
        for (int j = 1; j < 31; ++j)
        {
            if (i + j > n)
                break;
            from_bad += (chests[i + j] / (1 << j));
        }

        answer = std::max(answer, from_good + from_bad);
    }
    std::cout << answer << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}