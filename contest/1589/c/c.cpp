#include <bits/stdc++.h>

auto solve() -> void
{
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i] - 1 || a[i] > b[i])
        {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}