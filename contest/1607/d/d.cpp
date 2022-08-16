#include <bits/stdc++.h>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::string s;
    std::cin >> s;
    std::vector<int> blue, red;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            blue.push_back(a[i]);
        else
            red.push_back(a[i]);
    }
    // handle empty cases
    if (blue.empty())
    {
        std::sort(red.begin(), red.end());
        int need = 1;
        for (int i = 0; i < n; i++)
        {
            if (red[i] <= need)
                need++;
            else
            {
                std::cout << "NO"
                          << "\n";
                return;
            }
        }
        std::cout << "YES"
                  << "\n";
        return;
    }

    if (red.empty())
    {
        std::sort(blue.begin(), blue.end());
        int need = 1;
        for (int i = 0; i < n; i++)
        {
            if (blue[i] >= need)
                need++;
            else
            {
                std::cout << "NO"
                          << "\n";
                return;
            }
        }
        std::cout << "YES"
                  << "\n";
        return;
    }

    std::sort(red.begin(), red.end());
    std::sort(blue.begin(), blue.end());
    int need = 1;
    for (int i = 0; i < blue.size(); i++)
    {
        if (blue[i] >= need)
            need++;
        else
        {
            std::cout << "NO"
                      << "\n";
            return;
        }
    }
    for (int i = 0; i < red.size(); i++)
    {
        if (red[i] <= need)
            need++;
        else
        {
            std::cout << "NO"
                      << "\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}
