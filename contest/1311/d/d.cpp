#include <bits/stdc++.h>

#define int int64_t

const int MAXN = 1e5;
auto solve_but_right() -> void
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int ans = 1e9;
    using Numbers = std::tuple<int, int, int>;
    Numbers numbers;
    for (int A = 1; A <= 2 * a; A++)
    {
        for (int B = A; B <= MAXN; B += A)
        {
            int cur_ans = std::abs(a - A);
            cur_ans += std::abs(B - b);
            const int left = (c / B) * B;
            const int right = (c / B) * B + B;
            int better;
            const auto left_diff = std::abs(c - left);
            const auto right_diff = std::abs(c - right);
            if (left >= B && right >= B)
            {
                better = left_diff < right_diff ? left : right;
                cur_ans += std::min(left_diff, right_diff);
            }
            else if (left >= B)
            {
                better = left;
                cur_ans += left_diff;
            }
            else if (right >= B)
            {
                better = right;
                cur_ans += right_diff;
            }
            else
                assert(false);
            if (cur_ans < ans)
            {
                numbers = { A, B, better };
                ans = cur_ans;
            }
        }
    }
    std::cout << ans << '\n';
    const auto [answer_a, answer_b, answer_c] = numbers;
    std::cout << answer_a << ' ' << answer_b << ' ' << answer_c << '\n';
}

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve_but_right();

    return 0;
}