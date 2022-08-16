#include <bits/stdc++.h>

struct MostColoredAfter
{
    int substring_id{ -1 };
    int letters_colored_after{ 0 };
    int initial_position{ 0 };
};

auto get_occurrences(const std::string& text, const std::string& substring, const int substring_id,
                     std::vector<MostColoredAfter>& result)
{
    const auto substring_size = static_cast<int>(std::size(substring));
    for (std::size_t text_index = 0; text_index < std::size(text); ++text_index)
    {

        if (const auto end_position = text_index + substring_size - 1; end_position >= std::size(text))
            break;

        const auto text_starting_here = text.substr(text_index, substring_size);
        if (auto match = text_starting_here == substring; match)
        {
            int letters_already_colored = 0;
            // for all positions of the substring, we will record a match
            for (int i = 0; i < substring_size; ++i)
            {
                // we will color this current letter and possibly some more to the right
                const auto letters_colored_after = substring_size - i - 1;
                const auto starting_position = text_index;
                if (letters_colored_after >= result[text_index + i].letters_colored_after)
                {
                    result[text_index + i] = MostColoredAfter{ static_cast<int>(substring_id), letters_colored_after,
                                                  static_cast<int>(starting_position) };
                }
            }
        }
    }
}
auto get_occurrences(const std::string& text, const std::vector<std::string>& candidates)
{
    auto result = std::vector<MostColoredAfter>(std::size(text));
    for (int substring_id = 0; substring_id < std::size(candidates); ++substring_id)
    {
        const auto& candidate_substring = candidates[substring_id];
        get_occurrences(text, candidate_substring, substring_id, result);
    }
    return result;
}

auto solve() -> void
{
    std::string text;
    std::cin >> text;
    int size = std::size(text);

    int n;
    std::cin >> n;
    std::vector<std::string> substrings(n);
    for (auto& x : substrings)
        std::cin >> x;

    // check if it's possible
    const auto best_substrings = get_occurrences(text, substrings);
    for (int i = 0; i < size; ++i)
    {
        if (best_substrings[i].substring_id == -1)
        {
            std::cout << -1 << '\n';
            return;
        }
    }

    using Answer = std::pair<std::size_t, std::size_t>;
    std::vector<Answer> answer;
    int current_index = 0;
    while (current_index < size)
    {
        const auto letter = text.at(current_index);
        // we need to color letter here
        // greedily, we will choose the substring which will color the
        // most next letters too

        const auto& [id, colored_after, position] = best_substrings[current_index];
        const auto d_id = id;
        const auto d_colored_after = colored_after;
        const auto d_position = position;
        answer.emplace_back(id, position);
        current_index += 1 + colored_after;
    }
    std::cout << std::size(answer) << '\n';
    for (auto [id, pos] : answer)
        std::cout << id + 1 << " " << pos + 1 << '\n';
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