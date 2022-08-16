#include <bits/stdc++.h>

#define int int64_t

const int INF = 1e18;

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n+1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    int ans = -INF;
    for (int j = n; j >= 1; j--)
    {
        for (int i = j-1; i >= j - 2*k + 1; i--)
        {
            if (i <= 0) break;
            ans = std::max(ans, i * j - k * (a[j] bitor a[i]));
        }
    }
    std::cout << ans << "\n";
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}