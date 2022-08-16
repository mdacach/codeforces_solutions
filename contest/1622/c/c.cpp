#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> values(n);
    for (auto& x : values)
        std::cin >> x;
    std::sort(std::rbegin(values), std::rend(values));
    int cumulative_greatest = 0;
    const auto total_sum = std::accumulate(std::begin(values), std::end(values), int64_t{ 0 });
    int answer = 1e18;
    for (int replaces = 0; replaces < n; replaces++)
    {
        // if we were to replace, we will want to replace the greatest values
        // sum of the greatest values is stored into `cumulative_greatest`

        auto check = [&](const int subtractions)
        {
            // we always subtract from the smaller value
            auto new_smallest = values.back() - subtractions;
            int new_sum = ((replaces + 1) * new_smallest) + (total_sum - cumulative_greatest - values.back());
            return new_sum <= k;
        };

        if (check(0))
        {
            int steps = replaces;
            answer = std::min(answer, steps);
            cumulative_greatest += values.at(replaces);
            continue;
        }

        int l = 0; // always bad
        int r = 1; // always good
        while (!check(r)) r *= 2;
        while (r - l > 1)
        {
            const auto m = l + (r - l) / 2;
            if (check(m)) r = m;
            else l = m;
        }

        int steps = replaces + r;
        answer = std::min(answer, steps);
        cumulative_greatest += values.at(replaces);
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