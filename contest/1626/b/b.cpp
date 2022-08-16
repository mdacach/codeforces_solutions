#include <bits/stdc++.h>

auto sum_to_2dig_str(int sum) -> std::string
{
    if (sum <= 9)
        return "0" + std::to_string(sum);
    std::string res;
    while (sum)
    {
        res.push_back('0' + (sum % 10));
        sum /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

auto print(const std::string& s) -> void
{
    for (auto x : s)
        if (x != '*')
            std::cout << x;
    std::cout << '\n';
}

auto solve() -> void
{
    std::string s;
    std::cin >> s;
    int n = s.size();
    // try to find zero digit changes
    for (int i = n - 1; i > 0; i--)
    {
        int left = s[i - 1] - '0';
        int right = s[i] - '0';
        int sum = left + right;
        if (sum > 9)
        {
            auto str = sum_to_2dig_str(sum);
            s[i - 1] = str[0];
            s[i] = str[1];
            print(s);
            return;
        }
    }

    int sum = (s[0] - '0') + (s[1] - '0');
    auto str = sum_to_2dig_str(sum);
    s[1] = str[1];
    s = std::string(s.begin() + 1, s.end());
    print(s);
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