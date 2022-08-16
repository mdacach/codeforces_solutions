#include <bits/stdc++.h>

#define int int64_t

const int INF = 1e18;

auto solve() -> void
{
    int n;
    std::cin >> n;
    int smallest = 1e9;
    int greatest = 0;
    bool is_first = true;
    struct Segment
    {
        int L, R, cost;

        bool operator==(const Segment& other) const { return L == other.L && R == other.R && cost == other.cost; }
    };
    Segment containing_smallest{};
    Segment containing_greatest{};
    Segment previous_best_segment{};
    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        std::cin >> l >> r >> c;
        Segment current_segment{ l, r, c };
        if (is_first)
        {
            smallest = l;
            greatest = r;
            containing_smallest = current_segment;
            containing_greatest = current_segment;
            previous_best_segment = current_segment;
        }

        if (l < smallest || (l == smallest && c < containing_smallest.cost))
        {
            containing_smallest = current_segment;
            smallest = l;
        }

        if (r > greatest || (r == greatest && c < containing_greatest.cost))
        {
            containing_greatest = current_segment;
            greatest = r;
        }

        if (current_segment.L == smallest && current_segment.R == greatest)
        {
            bool previous_valid = previous_best_segment.L == smallest && previous_best_segment.R == greatest;
            if (current_segment.cost <= previous_best_segment.cost || !previous_valid)
                previous_best_segment = current_segment;
        }

        // answer is either both containing segments, or one of those alone
        const auto only_smallest = [&]
        {
            if (containing_smallest.R < greatest)
                return INF;
            return containing_smallest.cost;
        }();

        const auto only_greatest = [&]
        {
            if (containing_greatest.L > smallest)
                return INF;
            return containing_greatest.cost;
        }();

        const auto both = [&]
        {
            int64_t total_cost = 0;
            if (containing_smallest == containing_greatest)
            {
                total_cost = containing_greatest.cost;
            }
            else
            {
                total_cost += containing_smallest.cost;
                total_cost += containing_greatest.cost;
            }
            return total_cost;
        }();

        const auto current_answer = [&] {
            if (previous_best_segment.L == smallest && previous_best_segment.R == greatest)
                return previous_best_segment.cost;
            return INF;
        }();

        std::cout << std::min({only_smallest, only_greatest, both, current_answer}) << '\n';
        is_first = false;
    }
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