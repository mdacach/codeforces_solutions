#include <bits/stdc++.h>

std::map<std::string, int> freq;
auto count_substrings(const std::string& word)
{
    // small is size 3
    int n = std::size(word);
    for (int i = 0; i < n; ++i)
    {
        if (i + 3 > n)
            break;
        std::string current = word.substr(i, 3);
        ++freq[current];
    }
}

auto solve() -> void
{
    // 1 -> 203
    // 2 -> 65905
    // 3 -> 232
    // 4 ->
    std::vector<std::string> answer_for_4;
    answer_for_4.emplace_back("blepharoconjunctivitis");
    answer_for_4.emplace_back("formaldehydesulphoxylic");
    answer_for_4.emplace_back("pneumoventriculography");
    answer_for_4.emplace_back("pseudolamellibranchiata"); // two of those
    answer_for_4.emplace_back("superacknowledgment");
    // 5 -> e
    // 6 -> emi

    std::string s;
    std::vector<std::string> words;
    while (std::cin >> s)
        words.push_back(s);

    for (const auto& w : words)
        count_substrings(w);

    auto& subs = freq;
    int max_value = 0;
    for (auto [w, f] : freq)
    {
        max_value = std::max(f, max_value);
    }
    std::vector<std::string> maxs;
    for (auto [w, f] : freq)
    {
        if (f == max_value)
            maxs.push_back(w);
    }

    std::cout << freq["ati"];
    for (auto w : maxs) std::cout << w << '\n';
    return;
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const auto path = "/home/crs/cf/epic/e/files/words.txt";
    freopen(path, "r", stdin);

    int t = 1;
    //    std::cin >> t;
    while (t--)
        solve();

    return 0;
}