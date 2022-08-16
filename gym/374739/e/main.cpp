#include <bits/stdc++.h>

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    int64_t initial_answer = 0;
    for (uint32_t i = 0; i < n; i += 2)
        initial_answer += a[i];

    int64_t answer = 0;
    // starting at 0
    {
        std::vector<int> differences;
        for (uint32_t i = 1; i < n; i += 2)
            differences.push_back(a[i] - a[i - 1]);
        int64_t best_sum = 0;
        int64_t current_sum = 0;
        for (const auto& x : differences)
        {
            current_sum = std::max<int64_t>(current_sum + x, 0);
            best_sum = std::max(best_sum, current_sum);
        }
        answer = initial_answer + best_sum;
    }

    // starting at 1
    {
        std::vector<int> differences;
        for (uint32_t i = 2; i < n; i += 2)
            differences.push_back(a[i - 1] - a[i]);
        int64_t best_sum = 0;
        int64_t current_sum = 0;
        for (const auto& x : differences)
        {
            current_sum = std::max<int64_t>(current_sum + x, 0);
            best_sum = std::max(best_sum, current_sum);
        }
        answer = std::max(answer, initial_answer + best_sum);
    }
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