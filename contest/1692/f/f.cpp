#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    for (auto& x : a)
        x = x % 10;

    std::map<int, int> digits_to_count{};
    for (const auto& d : a)
        ++digits_to_count[d];

    std::vector<std::tuple<int, int, int>> valid_digits{};
    for (int d1 = 0; d1 <= 9; ++d1)
        for (int d2 = 0; d2 <= 9; ++d2)
            for (int d3 = 0; d3 <= 9; ++d3)
                if ((d1 + d2 + d3) % 10 == 3)
                    valid_digits.emplace_back(d1, d2, d3);

    for (const auto [d1, d2, d3] : valid_digits)
    {
        --digits_to_count[d1];
        --digits_to_count[d2];
        --digits_to_count[d3];

        const auto has_d1 = digits_to_count[d1] >= 0;
        const auto has_d2 = digits_to_count[d2] >= 0;
        const auto has_d3 = digits_to_count[d3] >= 0;
        if (has_d1 && has_d2 && has_d3)
        {
            std::cout << "YES\n";
            return;
        }

        // undo what was changed
        ++digits_to_count[d1];
        ++digits_to_count[d2];
        ++digits_to_count[d3];
    }

    std::cout << "NO\n";
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