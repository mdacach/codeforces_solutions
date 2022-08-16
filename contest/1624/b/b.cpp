#include <bits/stdc++.h>

auto solve() -> void
{
    int a, b, c;
    std::cin >> a >> b >> c;
    // we can test for each number being multiplied

    // if we were to multiply a, is it possible?
    // after some arithmetic:
    {
        // to multiply a
        const auto num = 2*b - c;
        const auto den = a;
        if (num % den == 0 && num >= den)
        {
            std::cout << "YES\n";
            return;
        }
    }
    {
        // to multiply b
        const auto num = a + c;
        const auto den = 2 * b;
        if (num % den == 0 && num >= den)
        {
            std::cout << "YES\n";
            return;
        }
    }
    {
        // to multiply c
        const auto num = 2*b - a;
        const auto den = c;
        if (num % den == 0 && num >= den)
        {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();

    return 0;
}