#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;

    std::string s_no_b, t_no_b;
    for (auto c : s)
        if (c != 'b')
            s_no_b.push_back(c);
    for (auto c : t)
        if (c != 'b')
            t_no_b.push_back(c);
    if (s_no_b != t_no_b)
    {
        std::cout << "NO\n";
        return;
    }

    std::map<char, std::vector<int>> char_indexes_s;
    std::map<char, std::vector<int>> char_indexes_t;
    for (int i = 0; i < n; ++i)
    {
        const auto char_s = s[i];
        if (char_s != 'b')
            char_indexes_s[char_s].push_back(i);
        const auto char_t = t[i];
        if (char_t != 'b')
            char_indexes_t[char_t].push_back(i);
    }

    const auto& as_in_s = char_indexes_s['a'];
    const auto& as_in_t = char_indexes_t['a'];
    for (int i = 0; i < (int) std::size(as_in_s); ++i)
    {
        if (as_in_s[i] > as_in_t[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    const auto& cs_in_s = char_indexes_s['c'];
    const auto& cs_in_t = char_indexes_t['c'];
    for (int i = 0; i < (int) std::size(cs_in_s); ++i)
    {
        if (cs_in_s[i] < cs_in_t[i])
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

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}