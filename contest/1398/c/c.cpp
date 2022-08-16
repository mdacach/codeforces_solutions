#include <bits/stdc++.h>

auto solve() -> void {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto values = [&] {
        std::vector<int> values;
        for (const auto &c: s) {
            values.push_back(static_cast<int>(c - '0'));
        }
        return values;
    }();
    std::for_each(std::begin(values), std::end(values), [&](auto &value) { --value; });
    std::map<int64_t, int> frequency_map;
    int64_t accumulated = 0;
    frequency_map[0] = 1;
    for (const auto &x: values) {
        accumulated += x;
        ++frequency_map[accumulated];
    }
    int64_t ans = 0;
    for (const auto &[value, frequency]: frequency_map) {
        ans += 1LL * frequency * (frequency - 1) / 2;
    }
    std::cout << ans << '\n';
}

auto main() -> int32_t {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}