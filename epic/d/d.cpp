#include <bits/stdc++.h>

struct letter
{
    char ch;
    int freq;

    bool operator<(const letter& rhs) const
    {
        if (freq == rhs.freq)
            return ch < rhs.ch;
        return freq > rhs.freq;
    }
};

auto solve() -> void
{
    std::string s;
    std::cin >> s;

    std::set<letter> set;
    std::map<char, int> f;
    for (auto c : s)
        ++f[c];
    for (auto [a, b] : f)
        set.insert({ a, b });

    std::string answer;
    char previous = '0';
    while (!set.empty())
    {
        auto most = std::begin(set);
        if (most->ch != previous)
        {
            answer.push_back(most->ch);
            previous = most->ch;

            auto tmp = *most;
            --tmp.freq;
            if (tmp.freq > 0)
                set.insert(tmp);
            set.erase(most);
        }
        else
        {
            if (std::size(set) >= 2)
            {
                auto second_most = std::next(most);
                assert(second_most->ch != most->ch);
                answer.push_back(second_most->ch);
                previous = second_most->ch;

                auto tmp = *second_most;
                --tmp.freq;
                if (tmp.freq > 0)
                    set.insert(tmp);
                set.erase(second_most);
            }
            else
            {
                answer.push_back(most->ch);
                previous = most->ch;

                auto tmp = *most;
                --tmp.freq;
                if (tmp.freq > 0)
                    set.insert(tmp);
                set.erase(most);
            }
        }
    }
    std::cout << answer << '\n';
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