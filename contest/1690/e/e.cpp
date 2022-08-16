#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::sort(std::begin(a), std::end(a), [k](auto lhs, auto rhs) { return (lhs % k) < (rhs % k); });

    int64_t answer = 0;
    std::vector<int> taken(n);
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        const auto left_value = a[left];
        const auto right_value = a[right];
        if ((left_value % k) + (right_value % k) >= k)
        {
            taken[left] = taken[right] = 1;
            answer += (left_value + right_value) / k;
            left += 1; right -= 1;
        }
        else
            left += 1;
    }

    std::vector<int> not_taken;
    for (int i = 0; i < n; ++i)
    {
        if (!taken[i])
            not_taken.push_back(a[i]);
    }

    assert(std::size(not_taken) % 2 == 0);
    for (int i = 1; i < std::size(not_taken); i += 2)
        answer += (not_taken[i - 1] + not_taken[i]) / k;

    std::cout << answer << '\n';
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