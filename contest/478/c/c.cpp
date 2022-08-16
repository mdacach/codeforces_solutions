#include <bits/stdc++.h>

#define int int64_t

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, g, b;
    std::cin >> r >> g >> b;
    std::vector<int> all({ r, g, b });
    std::sort(all.begin(), all.end());
    if (all[2] >= 2 * (all[0] + all[1])) std::cout << all[0] + all[1];
    else std::cout << (all[0] + all[1] + all[2]) / 3;
    std::cout << "\n";

    return 0;
}