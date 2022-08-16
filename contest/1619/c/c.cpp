#include <bits/stdc++.h>

auto as_int(char c) -> int
{
    return c - '0';
}

auto as_char(int n) -> char
{
    return '0' + n;
}

auto solve() -> void
{
    std::string a, s;
    std::cin >> a >> s;
    std::reverse(std::begin(a), std::end(a));
    std::reverse(std::begin(s), std::end(s));
    int current_s_index = 0;
    int current_a_index = 0;
    std::string b;
    while (current_s_index != s.size())
    {
        int have;
        if (current_a_index >= a.size())
            have = 0;
        else
            have = as_int(a[current_a_index]);
//        if (have == 0 && current_a_index < a.size())
//        {
//            current_a_index++;
//            continue;
//        }
        int want = as_int(s[current_s_index]);
        if (want < have)
        {
            int put = 10 + want - have;
            b.push_back(as_char(put));
            // make sure the next digit is a 1
            if (current_s_index == s.size() - 1 || s[current_s_index + 1] != '1')
            {
                std::cout << -1 << '\n';
                return;
            }
            current_s_index += 2; // already used the next digit
        }
        else
        {
            b.push_back(as_char(want - have));
            current_s_index++;
        }
        current_a_index++;
        const auto s_finished = current_s_index >= s.size();
        const auto a_finished = current_a_index >= a.size();
        if (s_finished && !a_finished)
        {
            std::cout << -1 << '\n';
            return;
        }
    }
    std::reverse(std::begin(b), std::end(b));
    int leading_zeros = 0;
    for (const auto c : b)
    {
        if (c == '0')
            leading_zeros++;
        else
            break;
    }
    std::cout << std::string(std::begin(b) + leading_zeros, std::end(b)) << '\n';
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