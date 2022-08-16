#include <bits/stdc++.h>

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<int> values(n);
    for (auto& x : values)
    {
        char ch;
        std::cin >> ch;
        if (ch == '-')
            x = -1;
        else
            x = 1;
    }

    uint32_t promising_substrings = 0;
    for (std::size_t start = 0; start < n; ++start)
    {
        int current_balance = 0;
        uint32_t current_pairs = 0;
        bool used_for_last_pair = false;
        for (std::size_t end = start; end < n; ++end)
        {
            current_balance += values[end];
            if (end > start)
            {
                if (values[end - 1] == -1 && values[end] == -1)
                {
                    if (used_for_last_pair)
                        used_for_last_pair = false;
                    else
                    {
                        ++current_pairs;
                        used_for_last_pair = true;
                    }
                }
            }
            if (current_balance == 0)
            {
                ++promising_substrings;
                continue;
            }

            // each operation increases current_balance by 3
            if (current_balance % 3 == 0)
            {
                if (current_balance > 0)
                    continue; // we can only increase it;
                const auto needed_pairs = std::abs(current_balance) / 3;
                if (current_pairs >= needed_pairs)
                    ++promising_substrings;
            }
        }
    }
    std::cout << promising_substrings << '\n';
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