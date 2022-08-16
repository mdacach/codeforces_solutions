#include <bits/stdc++.h>

const int INF = 1e9;

auto solve() -> void
{
    int len, desired_sum;
    std::cin >> len >> desired_sum;

    std::vector<int> values(len + 1);
    for (std::size_t i = 1; i <= len; ++i)
        std::cin >> values.at(i);

    int answer = INF;
    std::map<int, int> sum_to_first_position = { { 0, 0 } };
    int current_sum = 0;
    for (int i = 1; i <= len; ++i)
    {
        current_sum += values.at(i);

        // if it is 0, we already have a prior position for this sum
        if (values.at(i) == 1)
            sum_to_first_position[current_sum] = i;

        int removed_from_right = len - i;
        int need_to_remove = current_sum - desired_sum;
        if (sum_to_first_position.find(need_to_remove) != std::end(sum_to_first_position))
        {
            int removed_from_left = sum_to_first_position[need_to_remove];

            int this_answer = removed_from_left + removed_from_right;
            answer = std::min(this_answer, answer);
        }
    }

    std::cout << (answer == INF ? -1 : answer)  << '\n';
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