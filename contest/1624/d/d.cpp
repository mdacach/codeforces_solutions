#include <bits/stdc++.h>

auto solve() -> void
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::map<char, int> count;
    for (const auto& c : s)
        count[c]++;

    int to_be_middle = 0;
    int total_even = 0;
    for (auto& [c, cnt] : count)
    {
        if (cnt % 2)
        {
            to_be_middle++;
            cnt--;
        }
        total_even += cnt;
    }

    // test both approaches
    // we could either make everyone be ODD
    // or everyone be EVEN

    const auto all_odd = [=]
    {
        int answer = 0;
        int even = total_even;
        if (to_be_middle >= k)
            answer = 1;
        else
        {
            int missing = k - to_be_middle;
            // let's get those from pairs
            even -= missing;
            if (even % 2)
                even--;
            answer = 1;
        }
        // then divide the EVEN evenly
        int pairs = even / 2;
        // we have k strings to distribute these pairs evenly
        return answer + (pairs / k * 2);
    }();

    const auto all_even = [=]
    {
        int answer = 0;
        // then divide the EVEN evenly
        int pairs = total_even / 2;
        // we have k strings to distribute these pairs evenly
        return answer + (pairs / k * 2);
    }();

    std::cout << std::max(all_odd, all_even) << '\n';
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