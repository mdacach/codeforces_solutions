#include <bits/stdc++.h>


const int MOD = 1e9 + 7;

int binary_expo(int b, int e)
{
    int res = 1;
    while (e)
    {
        if (e & 1) res = (1LL * res * b) % MOD;
        b = (1LL * b * b) % MOD;
        e = e >> 1;
    }
    return res;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int ways_for_a_kind = (binary_expo(2, m) - 1 + MOD) % MOD;
    int ans = binary_expo(ways_for_a_kind, n);
    std::cout << ans << "\n";

    return 0;
}
