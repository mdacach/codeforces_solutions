#include <bits/stdc++.h>

auto solve() -> void
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::sort(std::rbegin(a), std::rend(a));
    std::vector<int> sum;
    int current_sum = 0;
    for (auto x : a)
    {
        current_sum += x;
        sum.push_back(current_sum);
    }

    // index + 1 = number of candies to eat
    while (q--)
    {
        int x;
        std::cin >> x;

        auto bigger = std::lower_bound(std::begin(sum), std::end(sum), x);
        if (bigger == std::end(sum))
            std::cout << -1 << '\n';
        else
            std::cout << std::distance(std::begin(sum), bigger) + 1 << '\n';
    }
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