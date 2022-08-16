#include <bits/stdc++.h>

auto solve() -> void
{
    int n, initial_iq;
    std::cin >> n >> initial_iq;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    std::vector<int> bad_indexes;
    for (int i = 0; i < n; ++i)
        if (a[i] > initial_iq)
            bad_indexes.push_back(i);

    // after some bad index, we will be able to take all contests
    auto compute_leftover_iq_after_suffix = [&](int starting_index)
    {
        int current_iq = initial_iq;
        // we must be able to take every contest here
        for (int i = starting_index; i < n; ++i)
            if (a[i] > current_iq)
                current_iq -= 1;
        return current_iq;
    };

    auto check_middle = [&](int middle)
    {
        if (middle == -1)
            return false;
        if (middle == std::size(bad_indexes))
            return true;
        return compute_leftover_iq_after_suffix(bad_indexes[middle]) >= 0;
    };

    int left = -1;                      // never possible
    int right = std::size(bad_indexes); // always possible
    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;
        if (check_middle(middle))
            right = middle;
        else
            left = middle;
    }

    // reconstruct the answer
    std::string answer(n, '0');
    int right_index = 0;
    if (right == std::size(bad_indexes))
        right_index = n;
    else
        right_index = bad_indexes[right];
    for (int i = right_index; i < n; ++i)
        answer[i] = '1';
    // we may be able to take some "good" contests to the left of this yet
    for (int i = right_index - 1; i >= 0; --i)
        if (a[i] <= initial_iq)
            answer[i] = '1';
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