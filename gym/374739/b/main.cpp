#include <bits/stdc++.h>

auto ceil(int a, int b) -> int
{
    return (a + b - 1) / b;
}

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::sort(std::begin(s), std::end(s));
    if (s[0] != s[k - 1])
    {
        std::cout << s[k - 1] << '\n';
        return;
    }
    std::cout << s[0]; // all strings start with this letter
    if (s[k] != s[n - 1])
    {
        // it's better to put all letters in the first answer, as we put the big letters
        // as far as possible, and that's better for lexicographical order
        for (int i = k; i < n; ++i)
            std::cout << s[i];
        std::cout << '\n';
    }
    else
    {
        // all letters are the same, so let's minimize the length of the strings instead
        int remaining_letters = n - k;
        for (int i = 0; i < ceil(remaining_letters, k); ++i)
            std::cout << s[n-1];
        std::cout << '\n';
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