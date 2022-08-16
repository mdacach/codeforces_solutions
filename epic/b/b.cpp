#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::sort(std::begin(a), std::end(a));
    int desired_sum = a.front() + a.back();
    int left = 0, right = n - 1;
    while (left < right)
    {
        int current_sum = a[left] + a[right];
        if (current_sum != desired_sum)
        {
            std::cout << -1 << '\n';
            return;
        }
        ++left;
        --right;
    }
    std::cout << desired_sum << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();

    return 0;
}