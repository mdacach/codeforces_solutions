#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<int> values(n);
    for (auto& x : values)
        std::cin >> x;
    std::reverse(std::begin(values), std::end(values));

    // can we make every pile have at least X?
    auto check = [&](const int X)
    {
        // for each pile, there's no use to have MORE than X
        // so let's move all stones we can, keeping the value >= X
        auto piles = values;
        for (int i = 0; i < n - 2; i++)
        {
            int can_move = piles[i] - X;
            if (can_move < 0)
                return false;
            // as there is no "borrowing", we can't ever move right now more than initially we have
            // because we're doing left to right, so even if this node would END UP with more stones,
            // we can't move them anywhere else.
            can_move = std::min(can_move, values[i]);
            int d = can_move / 3; // must be a multiple of 3
            // then we move d to i+1 and 2d to i+2
            piles[i] -= 3 * d;
            piles[i + 1] += d;
            piles[i + 2] += 2 * d;
        }

        return !std::any_of(std::begin(piles), std::end(piles), [&X](const auto& item) { return item < X; });
    };

    int L = 0; // always good
    int R = 1; // always bad
    while (check(R))
        R *= 2;
    while (R - L > 1)
    {
        int M = L + (R - L) / 2;
        if (check(M))
            L = M;
        else
            R = M;
    }
    std::cout << L << '\n';
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