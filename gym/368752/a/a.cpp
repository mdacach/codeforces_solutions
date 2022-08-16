#include <bits/stdc++.h>

auto is_palindrome(const std::string& s) -> bool
{
    std::size_t n = s.size();
    for (std::size_t i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::vector<std::string> strings(n);
    for (auto& s : strings)
        std::cin >> s;

    for (const auto& s : strings)
    {
        if (is_palindrome(s))
        {
            std::cout << "YES\n";
            return;
        }
    }

    auto exists = [&](const auto& s, const auto& pool) { return pool.find(s) != std::end(pool); };

    // a palindrome will then encompass two strings
    // a "left" one and a "right" one
    // s1 + s2 or s2 + s1
    auto check_possible_as_left = [&](const auto& s, const auto& pool)
    {
        // if size two, we need it exactly
        if (s.size() == 2)
        {
            auto want = s;
            std::reverse(std::begin(want), std::end(want));
            // we do not need to check for equality here, because it would be
            // a palindrome, and we would have already returned from this solve function

            if (exists(want, pool))
                return true;
        }
        else
        {

            // if size three, we could use the last character as a middle one
            assert(s.size() == 3);
            // using the last one as middling
            {
                auto want = std::string(std::begin(s), std::prev(std::end(s)));
                std::reverse(std::begin(want), std::end(want));

                if (exists(want, pool))
                    return true;
            }

            // using whole string
            {
                auto want = std::string(std::begin(s), std::end(s));
                std::reverse(std::begin(want), std::end(want));

                if (exists(want, pool))
                    return true;
            }
        }
        return false;
    };

    auto check_possible_as_right = [&](const auto& s, const auto& pool)
    {
        // if size two, we need it exactly
        if (s.size() == 2)
        {
            auto want = s;
            std::reverse(std::begin(want), std::end(want));
            // we do not need to check for equality here, because it would be
            // a palindrome, and we would have already returned from this solve function

            if (exists(want, pool))
                return true;
        }
        else
        {

            // if size three, we could use the first character as a middle one
            assert(s.size() == 3);
            // using the last one as middling
            {
                auto want = std::string(std::next(std::begin(s)), std::end(s));
                std::reverse(std::begin(want), std::end(want));

                if (exists(want, pool))
                    return true;
            }

            // using whole string
            {
                auto want = std::string(std::begin(s), std::end(s));
                std::reverse(std::begin(want), std::end(want));

                if (exists(want, pool))
                    return true;
            }
        }
        return false;
    };

    std::multiset<std::string> to_the_right, to_the_left;
    for (const auto& s : strings)
        to_the_right.insert(s);
    for (int i = 0; i < n; i++)
    {
        const auto current_string = strings[i];
        if (check_possible_as_left(current_string, to_the_right) ||
            check_possible_as_right(current_string, to_the_left))
        {
            std::cout << "YES\n";
            return;
        }

        to_the_left.insert(current_string);
        to_the_right.erase(to_the_right.find(current_string));
    }

    std::cout << "NO\n";
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