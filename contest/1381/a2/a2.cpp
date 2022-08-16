#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    // fix one at a time, starting from suffix
    std::vector<int> ans;
    int inversions = 0;   // keep track of number of inversion from beginning
    int l = 0, r = n - 1; // active part of our range, sometimes will be flipped
    for (int i = n - 1; i >= 0; i--)
    {
        if (inversions % 2 == 0)
        {
            if (a[r] == b[i])
            {
                if (r < l)
                    r++;
                else
                    r--;
                continue;
            }

            if (a[l] == b[i])
            {
                ans.push_back(1);
                ans.push_back(i + 1);
            }
            else
                ans.push_back(i + 1);
        }
        else
        {
            if (a[r] != b[i])
            {
                if (r < l)
                    r++;
                else
                    r--;
                continue;
            }

            if (a[l] != b[i])
            {
                ans.push_back(1);
                ans.push_back(i + 1);
            }
            else
                ans.push_back(i + 1);
        }

        inversions++;
        if (l < r)
            l++;
        else
            l--;
        std::swap(l, r);
    }
    std::cout << ans.size() << " ";
    for (auto x : ans)
        std::cout << x << " ";
    std::cout << "\n";
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