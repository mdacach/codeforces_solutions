#include <bits/stdc++.h>

void solve()
{
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    int accumulative = 0;
    int ans = -1e9;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(a[i] - accumulative, ans);
        accumulative += a[i] - accumulative;
    }
    std::cout << ans << "\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}
