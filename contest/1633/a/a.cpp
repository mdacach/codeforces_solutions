#include <bits/stdc++.h>

auto solve() -> void
{
    std::vector<int> multiples;
    for (int i = 7; i <= 999; i += 7)
        multiples.push_back(i);
    auto size = [](int number)
    {
        if (number == 0)
            return 1;
        int res = 0;
        while (number)
        {
            res++;
            number /= 10;
        }
        return res;
    };
    int n;
    std::cin >> n;

    int global_answer = 100;
    int resulting_number = -1;
    for (const auto m : multiples)
    {
        if (size(m) == size(n))
        {
            const auto n_str = std::to_string(n);
            const auto m_str = std::to_string(m);
            int changes_needed = 0;
            for (std::size_t i = 0; i < n_str.size(); i++)
                changes_needed += n_str[i] != m_str[i];
            if (changes_needed <= global_answer)
            {
                global_answer = changes_needed;
                resulting_number = m;
            }
        }
    }
    // there should always be an answer
    assert(resulting_number != -1);
    std::cout << resulting_number << '\n';
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