#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;
    std::sort(std::begin(a), std::end(a));
    // We can either take the leftmost or the rightmost as the final stop
    int leftmost = a.front();
    int rightmost = a.back();
    int64_t answer = 0;
    if (std::abs(leftmost) > std::abs(rightmost))
    {
        // Take lefmost and possibly k-1 elements
        int nums_to_erase = 1;
        for (int i = 1; i < k; ++i)
        {
            int current = a[i];
            // If leftmost is negative and next one is positive, we can't take them
            if (std::signbit(leftmost) != std::signbit(current))
                break;
            ++nums_to_erase;
        }
        a.erase(std::begin(a), std::begin(a) + nums_to_erase);
        answer += std::abs(leftmost);
    }
    else
    {
        // Take rightmost and possibly k-1 elements
        int nums_to_erase = 1;
        for (int i = 1; i < k; ++i)
        {
            int current = a[n - i - 1];
            // If leftmost is negative and next one is positive, we can't take them
            if (std::signbit(rightmost) != std::signbit(current))
                break;
            ++nums_to_erase;
        }
        for (int i = 0; i < nums_to_erase; ++i)
            a.pop_back();
        answer += std::abs(rightmost);
    }

    // Split negative and positive
    std::vector<int> negative;
    for (const auto& x : a)
        if (x < 0)
            negative.push_back(x);

    std::vector<int> positive;
    for (const auto& x : a)
        if (x > 0)
            positive.push_back(x);

    std::sort(std::rbegin(negative), std::rend(negative));
    std::sort(std::begin(positive), std::end(positive));

    {
        int counter = 0;
        while (!negative.empty())
        {
            if (counter == 0)
                answer += 2 * std::abs(negative.back());
            negative.pop_back();
            ++counter;
            if (counter == k)
                counter = 0;
        }
    }

    {
        int counter = 0;
        while (!positive.empty())
        {
            if (counter == 0)
                answer += 2 * std::abs(positive.back());
            positive.pop_back();
            ++counter;
            if (counter == k)
                counter = 0;
        }
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