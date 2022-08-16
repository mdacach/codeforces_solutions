#include <bits/stdc++.h>

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::sort(std::begin(a), std::end(a));
    if (n == 1)
    {
        if (a.front() > 1)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
        return;
    }
    const auto last = a.back();
    const auto second_last = a.at(std::size(a) - 2);
    if (last >= second_last + 2)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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