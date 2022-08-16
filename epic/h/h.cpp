#include <bits/stdc++.h>

#define int int64_t

auto solve() -> void
{
    int L, R;
    std::cin >> L >> R;
    {

        int ans_xor = L;
        int ans_or = L;
        int ans_and = L;
        for (int x = L + 1; x <= R; ++x)
        {
            ans_xor ^= x;
            ans_or |= x;
            ans_and &= x;
        }

        std::cout << ans_xor << " " << ans_or << " " << ans_and << '\n';
    }
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