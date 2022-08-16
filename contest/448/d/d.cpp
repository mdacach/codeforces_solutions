#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    auto smaller = [&] (int x, int row) {
        return std::min((x - 1) / row, m);
    };

    auto check = [&] (int x) {
        int all_smaller = 0;
        for (int row = 1; row <= n; row++)
            all_smaller += smaller(x, row);
        return all_smaller < k;
    };
    int l = 1;
    int r = n * m + 1;
    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    std::cout << l << "\n";


    return 0;
}
