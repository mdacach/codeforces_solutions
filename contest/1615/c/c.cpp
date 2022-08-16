#include <bits/stdc++.h>

auto solve() -> void
{
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    if (a == b)
    {
        std::cout << 0 << '\n';
        return;
    }

    if (!std::any_of(std::begin(a), std::end(a), [](const auto& item) { return item == '1'; }))
    {
        std::cout << -1 << '\n';
        return;
    }

    // a pair of operations will swap a 1 and a 0
    // so we must count how many 1s we need to swap
    int answer = -1;
    {
        int should_be_0 = 0;
        int should_be_1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1' && b[i] == '0')
                should_be_0++;
            if (a[i] == '0' && b[i] == '1')
                should_be_1++;
        }
        if (should_be_0 == should_be_1)
            answer = should_be_0 + should_be_1;
    }

    // we can also try to invert the bits of the string first, and see
    // if that is better
    {
        int right_index = -1;
        for (int i = 0; i < n; i++)
            if (a[i] == b[i] && a[i] == '1')
                right_index = i;
        if (right_index == -1)
        {
            std::cout << answer << '\n';
            return;
        }
        for (int i = 0; i < n; i++)
            a[i] = a[i] == '1' ? '0' : '1';
        a[right_index] = '1';

        int should_be_0 = 0;
        int should_be_1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1' && b[i] == '0')
                should_be_0++;
            if (a[i] == '0' && b[i] == '1')
                should_be_1++;
        }
        if (should_be_0 == should_be_1)
        {
            int this_answer = should_be_0 + should_be_1 + 1; // 1 inversion at the beginning
            if (answer == -1)
                answer = this_answer;
            else
                answer = std::min(answer, this_answer);
        }
        std::cout << answer << '\n';
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