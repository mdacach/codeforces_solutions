#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    const auto highest_power_of_two = [value = n-1]
    {
        int p = 1;
        while (p <= value)
            p *= 2;
        return p / 2;
    }();
    std::deque<int> ans;
    for (int i = 0; i < highest_power_of_two; i++)
        ans.push_front(i);
    for (int i = highest_power_of_two; i < n; i++)
        ans.push_back(i);
    for (const auto x : ans) std::cout << x << " ";
    std::cout << '\n';
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