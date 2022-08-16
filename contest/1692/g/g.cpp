#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::vector<int> length_of_good_segments;
    for (int i = 0; i < n;)
    {
        int needed = 0;
        int segment_size = 0;
        while (i < n && a.at(i) > needed)
        {
            needed = a.at(i) / 2;
            ++i;
            ++segment_size;
        }
        length_of_good_segments.push_back(segment_size);
    }
    int64_t answer = 0;
    for (const auto& segment : length_of_good_segments)
    {
        if (segment < k + 1)
            continue;
        answer += segment - (k + 1) + 1;
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