#include <bits/stdc++.h>

#define int int64_t

const int MAX = 1e6 + 10;

std::array<bool, MAX> is_prime;

auto sieve()
{
    is_prime.fill(true);
    is_prime[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j < MAX; j += i)
            is_prime[j] = false;
    }
}

auto solve() -> void
{
    int size;
    std::cin >> size;
    int jump;
    std::cin >> jump;
    std::vector<int> values(size);
    for (int i = 0; i < size; i++)
        std::cin >> values[i];

    auto& primes = is_prime;
    int answer = 0;
    for (int i = 0; i < jump; i++)
    {
        int ones_to_the_left = 0;
        for (int j = i; j < size; j += jump)
        {
            int current_value = values[j];
            if (current_value == 1)
                ones_to_the_left++;
            else if (is_prime[current_value])
            {
                int ones_to_the_right = 0;
                j += jump;
                while (j < size && values[j] == 1)
                {
                    ones_to_the_right++;
                    j += jump;
                }
                j -= jump; // revert last jump
                // then we can do all ones to the left and all to the right
                answer += ones_to_the_left + ones_to_the_right + ones_to_the_left * ones_to_the_right;
                ones_to_the_left = ones_to_the_right;
            }
            else
            {
                ones_to_the_left = 0;
            }
        }
    }
    std::cout << answer << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}