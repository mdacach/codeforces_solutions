#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> explorers(n);
    for (auto& x : explorers)
        std::cin >> x;
    std::sort(std::begin(explorers), std::end(explorers));
    int available_explorers = 0;
    int groups = 0;
    for (auto x : explorers)
    {
        int needed_in_this_group = x;
        if (available_explorers + 1 >= needed_in_this_group)
        {
            assert(available_explorers + 1 == needed_in_this_group);
            groups += 1;
            available_explorers = 0;
        }
        else
            available_explorers += 1;
    }

    std::cout << groups << '\n';
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