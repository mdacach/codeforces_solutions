#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    // swap leftmost 1 with rightmost 0
    int leftmost_one = 0;
    int rightmost_zero = n - 1;
    std::vector<int> ans;
    while (leftmost_one < rightmost_zero)
    {
        if (s[leftmost_one] != '1')
            leftmost_one++;
        else if (s[rightmost_zero] != '0')
            rightmost_zero--;
        else
        {
            ans.push_back(leftmost_one + 1);
            ans.push_back(rightmost_zero + 1);
            leftmost_one++;
            rightmost_zero--;
        }
    }
    if (!ans.empty())
    {
        std::sort(ans.begin(), ans.end());
        std::cout << 1 << '\n';
        std::cout << ans.size() << " ";
        for (auto x : ans)
            std::cout << x << " ";
        std::cout << '\n';
    }
    else
    {
        std::cout << 0 << '\n';
    }
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}