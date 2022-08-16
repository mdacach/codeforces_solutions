#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::map<int, int> num_to_freq;
    for (auto x : a)
        ++num_to_freq[x];

    std::vector<int> eligible;
    for (auto [num, freq] : num_to_freq)
    {
        if (freq >= k)
            eligible.push_back(num);
    }

    if (eligible.empty())
    {
        std::cout << -1 << '\n';
        return;
    }

    int current_index = 0;
    std::vector<int> best_segment;
    std::vector<int> current_segment = { eligible.front() };
    while (current_index + 1 < (int) std::size(eligible))
    {
        int current = eligible.at(current_index);
        int next = eligible.at(current_index + 1);
        if (next == current + 1)
            current_segment.push_back(next);
        else
        {
            if (std::size(current_segment) > std::size(best_segment))
                best_segment = current_segment;
            current_segment = { next };
        }
        ++current_index;
    }
    if (std::size(current_segment) > std::size(best_segment))
        best_segment = current_segment;
    std::cout << best_segment.front() << " " << best_segment.back() << '\n';
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