#include <bits/stdc++.h>

auto choose(int a, int b) -> int
{
    if (a < b)
        return 0;
    int num = 1;
    for (int i = a - b + 1; i <= a; ++i)
        num *= i;
    for (int f = 1; f <= b; ++f)
        num /= f;
    return num;
}

auto solve() -> void
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int correct_position = 0;
    for (auto c : s1)
        correct_position += (c == '+' ? 1 : -1);

    // without the unrecognized
    int received_position = 0;
    int unrecognized = 0;
    for (auto c : s2)
    {
        if (c == '?')
            unrecognized += 1;
        else if (c == '+')
            received_position += 1;
        else
            received_position -= 1;
    }

    int delta = correct_position - received_position;
    // we have X unrecognized and want their difference to be `delta`
    // T total numbers
    // P positive N negative
    // P - N = delta
    // N = T - P
    // P = N + delta
    // P = T - P + delta
    // P = (T + delta) / 2
    // T choose this
    if ((unrecognized + delta) % 2 != 0)
    {
        std::cout << 0 << '\n';
        return;
    }
    int positives_wanted = (unrecognized + delta) / 2;
    if (positives_wanted < 0)
    {
        std::cout << 0 << '\n';
        return;
    }
    const long double ways = choose(unrecognized, positives_wanted);
    const long double den = std::pow(2, unrecognized);
    std::cout << std::fixed << std::setprecision(20);
    std::cout << ways / den << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //    std::cin >> t;
    while (t--)
        solve();

    return 0;
}