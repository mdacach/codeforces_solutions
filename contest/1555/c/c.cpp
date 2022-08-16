#include <bits/stdc++.h>

auto solve() -> void
{
    int m;
    std::cin >> m;
    std::vector<int> first_row(m + 1);
    for (int i = 0; i < m; ++i)
        std::cin >> first_row[i + 1];
    std::vector<int> second_row(m + 1);
    for (int i = 0; i < m; ++i)
        std::cin >> second_row[i + 1];

    std::vector<int> first_pref_sum(m + 1);
    for (int i = 0; i < m; ++i)
        first_pref_sum[i + 1] = first_pref_sum[i] + first_row[i + 1];
    std::vector<int> second_pref_sum(m + 1);
    for (int i = 0; i < m; ++i)
        second_pref_sum[i + 1] = second_pref_sum[i] + second_row[i + 1];

    auto first_sum = [&](int l, int r) { return first_pref_sum[r] - first_pref_sum[l - 1]; };
    auto second_sum = [&](int l, int r) { return second_pref_sum[r] - second_pref_sum[l - 1]; };

    int answer_bob = 2e9;
    for (int alice_changes = 1; alice_changes <= m; ++alice_changes)
    {
        int from_first = first_sum(1, alice_changes);
        int from_second = second_sum(alice_changes, m);

        int total_first = first_pref_sum[m];
        int total_second = second_pref_sum[m];
        int for_bob = std::max(total_first - from_first, total_second - from_second);
        if (for_bob <= answer_bob)
        {
            answer_bob = for_bob;
        }
    }
    std::cout << answer_bob << '\n';
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