#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> pos(2 * n + 10);
    std::vector<int> odd(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        odd[i] = x;
        pos[x] = i;
    }
    std::vector<int> even(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        even[i] = x;
        pos[x] = i;
    }
    std::vector<int> closest_odd(2 * n + 10);
    closest_odd[1] = pos[1];
    for (int x = 3; x <= 2 * n; x += 2)
        closest_odd[x] = std::min(closest_odd[x - 2], pos[x]);

    int ans = 1348237;
    for (int moves_on_even = 0; moves_on_even < n; moves_on_even++)
    {
        int front = even[moves_on_even];
        ans = std::min(ans, moves_on_even + closest_odd[front-1]);
    }
    std::cout << ans << "\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}
