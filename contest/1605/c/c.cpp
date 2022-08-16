#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<std::string> possible_answers = { "aa", "aba", "aca", "abca", "acba", "abbacca", "accabba" };
    for (const auto& ans : possible_answers)
    {
        if (s.find(ans) != std::string::npos)
        {
            std::cout << ans.size() << '\n';
            return;
        }
    }
    std::cout << -1 << '\n';
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