#include <bits/stdc++.h>

auto diff_letters(char c1, char c2)
{
    return std::max(c1, c2) - std::min(c1, c2);
}

auto diff_words(const std::string& s1, const std::string& s2)
{
    int res = 0;
    for (int i = 0; i < (int) std::size(s1); ++i)
        res += diff_letters(s1[i], s2[i]);
    return res;
}

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (auto& x : a)
        std::cin >> x;

    int best = 1e9;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            best = std::min(best, diff_words(a[i], a[j]));
    std::cout << best << '\n';
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