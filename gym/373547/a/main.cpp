#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> values;
    for (const auto& c : s)
        values.push_back(static_cast<int>(c - '0') - 1);
    std::map<uint64_t, uint32_t> frequency_map{ { 0, 1 } };
    uint64_t accumulated = 0;
    for (const auto& x : values)
    {
        accumulated += x;
        ++frequency_map[accumulated];
    }
    uint64_t ans = 0;
    for (const auto& [value, frequency] : frequency_map)
        ans += static_cast<int64_t>(frequency) * (frequency - 1) / 2;
    std::cout << ans << '\n';
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