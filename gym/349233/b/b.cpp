#include <bits/stdc++.h>

const int MAX_GCD = 1e6 + 5;

std::set<int> get_divisors(int n)
{
    std::set<int> divisors;
    for (int i = 1; 1LL * i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    return divisors;
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto&& x : a)
        std::cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int good_count = 0;
        std::map<int, int> divisors_count;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == a[i]) good_count++;
            if (a[j] <= a[i]) continue;
            int diff = a[j] - a[i];
            for (auto x : get_divisors(diff))
                divisors_count[x]++;
        }

        for (int j = 0; j < n; j++)
        {
            if (a[j] <= a[i])
                continue;

            int diff = a[j] - a[i];
            for (auto x : get_divisors(diff))
            {
                if (good_count + divisors_count[x] >= n/2)
                {
                    ans = std::max(ans, x);
                }
            }
        }

        if (good_count >= n/2)
        {
            std::cout << -1 << "\n";
            return;
        }
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
    {
        solve();
        /*
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (auto&& x : a)
            std::cin >> x;

        for (auto objective : a)
        {
            // want to make everything equal to this guy
            std::vector<int> diffs;
            diffs.reserve(a.size());
            for (auto other : a)
                diffs.push_back(other - objective); // may be negative, disconsider outside

            std::vector<std::vector<int>> picked(n+10, std::vector<int>(MAX_GCD));
            for (int i = 0; i < n; i++)
            {
                for (int g = 0; g < MAX_GCD; g++)
                {
                    // pick this difference
                    if (diffs[i] >= 0)
                    {
                        auto new_gcd = std::gcd(g, diffs[i]);
                        picked[i+1][new_gcd] = picked[i][g] + 1;
                    }
                    // do not pick
                    picked[i+1][g] = picked[i][g];
                }
            }

            int best = 0;
            for (int g = 0; g < MAX_GCD; g++)
            {
                if (picked[g][n] >= n/2) best = std::max(best, g);
            }
            std::cout << "best: " << best << "\n";
        }
        */
    }

    return 0;
}
