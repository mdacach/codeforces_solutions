#include <bits/stdc++.h>

const int N = 1e6 + 10;
const int MOD = (1 << 30);

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> divisors(N);
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j+=i)
            divisors[j]++;

    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    std::set<int> unique;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ans += divisors[i * j * k];
                ans %= MOD;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}
