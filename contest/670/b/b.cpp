#include <bits/stdc++.h>

#define int int64_t

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> id(n);
    for (auto&& x : id)
        std::cin >> x;

    // binary search for number of robots speaking

    auto ids_said = [&](int x) { return (x + 1) * x / 2; };
    auto check = [&](int x)
    {
        // sum from 1 to x
        return ids_said(x) <= k;
    };
    int l = 1;
    int r = 1e6;
    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    auto left = k - ids_said(l);
    if (left)
        std::cout << id[left - 1] << "\n";
    else
        std::cout << id[l - 1] << "\n";
    return 0;
}
