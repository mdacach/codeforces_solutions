#include <bits/stdc++.h>

/// Compute crossings for some wire going from `top` to `bot`
auto get_crossings(const int top, const int bot, const std::vector<int>& wires) -> int64_t
{
    std::vector<int> left(std::begin(wires), std::begin(wires) + top - 1);
    std::vector<int> right(std::begin(wires) + top, std::end(wires));

    // a crossing occurs if someone on the top left goes to bottom right or
    // the inverse
    int64_t crossings = 0;
    crossings += std::accumulate(std::begin(left), std::end(left), int64_t{ 0 },
                                 [bot](auto sum, auto current) { return sum + (current >= bot); });
    crossings += std::accumulate(std::begin(right), std::end(right), int64_t{ 0 },
                                 [bot](auto sum, auto current) { return sum + (current <= bot); });
    return crossings;
}

auto solve() -> void
{
    int n;
    std::cin >> n;

    std::vector<int> bottom(n);
    for (auto& x : bottom)
        std::cin >> x;

    int64_t crossings = 0;
    for (int top = 1; top <= n; ++top)
        crossings += get_crossings(top, bottom[top - 1], bottom);
    assert(crossings % 2 == 0); // each crossing was double-counted
    std::cout << crossings / 2 << '\n';
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