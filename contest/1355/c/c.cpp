#include <bits/stdc++.h>

#define int int64_t

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto bigger_or_equal_than = [](int x, int left, int right)
    {
        if (x > right)
            return 0LL;
        if (x < left)
            x = left;
        return right - x + 1LL;
    };

    auto arithmetic_sum = [] (int a, int b) {
        b--;
        b = std::max<int>(0, b);
        return (a * (a + 1) / 2) - (b * (b + 1) / 2);
    };

    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    int ans = 0;
    for (int y = B; y <= C; y++)
    {
        // x + y > z -> x > z - y
        int z = C;
        // how much can we go back with x?
        int min_x = z - y + 1; // must be at least this
        int left = A, right = B;
        int can = bigger_or_equal_than(min_x, left, right);
        // for each z we increase, the number of "can" decreases by 1
        // we will either extend the can or we don't have enough room in z
        int stop;
        int range_for_z = D - C + 1;
        int max = B - min_x + 1;
        if (min_x < A)
        {
            // some extra moves
            int extra = A - min_x;
            ans += can * std::min(extra, range_for_z);
            range_for_z -= std::min(extra, range_for_z);
        }
//        if (range_for_z > can && max > can)
//        {
//            int extra = max - can;
//            ans += can * extra;
//        }
        if (range_for_z >= can) // range for z
            stop = 0;
        else
            stop = can - (range_for_z - 1);
        ans += arithmetic_sum(can, stop);
    }
    std::cout << ans << "\n";

    return 0;
}