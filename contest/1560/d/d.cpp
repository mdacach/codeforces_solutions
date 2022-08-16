#include <bits/stdc++.h>

auto distance(int n, int64_t p) -> int
{
    std::vector<int> power_digits;
    while (p)
    {
        power_digits.push_back(p % 10);
        p /= 10;
    }

    std::vector<int> n_digits;
    while (n)
    {
        n_digits.push_back(n % 10);
        n /= 10;
    }

    std::reverse(std::begin(power_digits), std::end(power_digits));
    std::reverse(std::begin(n_digits), std::end(n_digits));

    int found = 0;
    for (const auto& d : n_digits)
    {
        if (d == power_digits.at(found))
        {
            found++;
            if (found == std::size(power_digits))
                break;
        }
    }

    int operations = static_cast<int>(std::size(n_digits)) - found + std::size(power_digits) - found;
    return operations;
}

auto solve() -> void
{
    int n;
    std::cin >> n;

    int answer = 1e9;

    int64_t p = 1;
    while (p <= 1e17)
    {
        answer = std::min(answer, distance(n, p));
        p *= 2;
    }
    std::cout << answer << '\n';
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