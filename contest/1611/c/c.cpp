#include <bits/stdc++.h>

auto solve()
{
    int n; std::cin >> n;
    std::vector<int> p(n);
    for (auto& x : p) std::cin >> x;
    if (n == 1)
    {
        std::cout << 1 << '\n';
        return;
    }
    bool reversed = false;
    if (p.front() != 1)
    {
        reversed = true;
        std::reverse(p.begin(), p.end());
    }
    std::reverse(p.begin() + 1, p.end());
    if (p[1] != n)
    {
        std::cout << -1 << '\n';
    } else
    {
        if (reversed) std::reverse(p.begin(), p.end());
        for (auto x : p) std::cout << x << " ";
        std::cout << '\n';
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}