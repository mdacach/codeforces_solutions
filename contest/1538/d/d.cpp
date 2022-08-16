#include <bits/stdc++.h>

// DO NOT LOOK AT THIS CODE IT'S ATROCIOUS!
auto get_factors(int n) -> std::map<int, int>
{
    std::map<int, int> factors;
    for (int i = 2; 1LL * i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            factors[i]++;
        }
    }
    if (n > 1)
        factors[n]++;
    return factors;
}

auto solve() -> void
{
    int a, b, k;
    std::cin >> a >> b >> k;
    const auto a_factors = get_factors(a);
    const auto b_factors = get_factors(b);

    int a_max_operations = 0;
    for (auto [p, e] : a_factors)
        a_max_operations += e; // we can remove each factor individually

    int b_max_operations = 0;
    for (auto [p, e] : b_factors)
        b_max_operations += e; // we can remove each factor individually

    int total_max = a_max_operations + b_max_operations; // both are 1 at the end
    int max_until_equal = 0;
    int min_until_equal = 0;
    int cnt_diff = 0;
    bool change = false;
    for (auto [p, e] : a_factors)
    {
        if (b_factors.find(p) == b_factors.end())
        {
            min_until_equal++;
            max_until_equal += e;
            change = true;
        }
        else
        {
            if (e > b_factors.at(p)) change = true;
            min_until_equal += e > b_factors.at(p);
            max_until_equal += std::max(e - b_factors.at(p), 0);
        }
    }
    if (change) cnt_diff++;
    change = false;
    for (auto [p, e] : b_factors)
    {
        if (a_factors.find(p) == a_factors.end())
        {
            min_until_equal++;
            max_until_equal += e;
            change = true;
        }
        else
        {
            if (e > a_factors.at(p)) change = true;
            min_until_equal += e > a_factors.at(p);
            max_until_equal += std::max(e - a_factors.at(p), 0);
        }
    }
    if (change) cnt_diff++;

    if (k == 1 && a == b)
    {
        std::cout << "NO\n";
        return;
    }



    if (k >= cnt_diff && k <= total_max)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    int cnt = 1;
    std::cin >> t;
    while (t--) {
//        if (cnt == 3033)
//        {
//            int a, b, k;
//            std::cin >> a >> b >> k;
//            std::cout << a << "." << b << "." << k << "\n";
//        }
        solve();
        cnt++;
    }

    return 0;
}