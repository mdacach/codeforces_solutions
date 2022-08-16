#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    auto min = *std::min_element(std::begin(a), std::end(a));
    auto answer = std::accumulate(std::begin(a), std::end(a), 0,
                                  [&min](auto sum, auto current_element) { return sum + current_element - min; });
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