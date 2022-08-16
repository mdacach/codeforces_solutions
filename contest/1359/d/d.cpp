#include <bits/stdc++.h>

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int ans = 0;
    for (int M = -30; M <= 30; M++)
    {
        std::vector<int> max_picking_M(n + 1, 0);
        std::vector<int> max_not_picking_M(n + 1, 0);
        // what can we do if biggest one is M?
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > M)
            {
                // can't pick this guy ever
                max_picking_M[i] = 0;
                max_not_picking_M[i] = 0;
            }
            else if (a[i] == M)
            {
                // pick it for the first time
                max_picking_M[i] = std::max(max_not_picking_M[i - 1] + M, max_picking_M[i]);
                // pick it again
                max_picking_M[i] = std::max(max_picking_M[i - 1] + M, max_picking_M[i]);
                // can't not pick it (would be zero)
            }
            else
            {
                // free to choose
                max_picking_M[i] = max_picking_M[i - 1] + a[i];
                max_not_picking_M[i] = std::max(max_not_picking_M[i - 1] + a[i], a[i]);
            }

            max_picking_M[i] = std::max(max_picking_M[i], 0);
            max_not_picking_M[i] = std::max(max_not_picking_M[i], 0);
            if (max_picking_M[i] != 0)
                ans = std::max(ans, max_picking_M[i] - M);
        }
        continue;
    }
    std::cout << ans << '\n';

    return 0;
}