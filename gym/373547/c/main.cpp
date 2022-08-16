#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<int> visited;
    bool yes = true;
    for (int k = 0; k < n; k++)
    {
        auto new_value = (k + a[k]) % n;
        if (new_value < 0)
            new_value += n;
        if (visited.find(new_value) != std::end(visited))
            yes = false;
        visited.insert(new_value);
    }
    std::cout << (yes ? "YES\n" : "NO\n");
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