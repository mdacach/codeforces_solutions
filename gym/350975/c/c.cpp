#include <bits/stdc++.h>

#define int int64_t

const int N = 2e5 + 10;
const int MOD = 998'244'353;

int fact[N];

int mul(int a, int b)
{
    return a * b % MOD;
}

int fexp(int b, int e)
{
    assert(e >= 0 && b >= 0);
    int res = 1;
    while (e)
    {
        if (e & 1)
            res = mul(res, b);
        b = mul(b, b);
        e = e >> 1;
    }
    return res;
}

int inv(int b)
{
    return fexp(b, MOD - 2);
}

int choose(int a, int b)
{
    int num = fact[a];
    int den1 = fact[a - b];
    int den2 = fact[b];
    return mul(num, inv(mul(den1, den2)));
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::map<int, int> cnt;
    for (auto& x : a)
        cnt[x]++;
    const auto max = *std::max_element(a.begin(), a.end());
    if (cnt[max] > 1)
    {
        std::cout << fact[n] << "\n";
    }
    else if (cnt[max - 1] == 0)
    {
        std::cout << 0 << "\n";
    }
    else
    {
        int ans = fact[n];
        auto bad = cnt[max - 1];
        for (int i = 0; i < n; i++)
        {
            if (i < bad) continue;
            ans -= mul(mul(choose(i, bad), fact[bad]), fact[n - bad - 1]);
            if (ans < 0) ans += MOD;
        }
        std::cout << ans << "\n";
    }
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}
