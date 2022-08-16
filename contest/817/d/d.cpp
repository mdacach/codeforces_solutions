#include <bits/stdc++.h>

auto main() -> int32_t
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    auto GetLeft = [&]
    {
        std::stack<int> nearest_smaller; // to the left (index)
        nearest_smaller.push(-1);
        std::vector<int> left(n);
        for (int i = 0; i < n; i++)
        {
            int index = nearest_smaller.top();
            while (index != -1 && a[index] >= a[i])
            {
                nearest_smaller.pop();
                index = nearest_smaller.top();
            }
            left[i] = index;
            nearest_smaller.push(i);
        }
        return left;
    };

    auto GetRight = [&]
    {
        std::stack<int> nearest_smaller; // to the left (index)
        nearest_smaller.push(n);
        std::vector<int> right(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int index = nearest_smaller.top();
            while (index != n && a[index] >= a[i])
            {
                nearest_smaller.pop();
                index = nearest_smaller.top();
            }
            right[i] = index;
            nearest_smaller.push(i);
        }
        return right;
    };

    auto left = GetLeft();
    auto right = GetRight();

    int sum_mins = 0;
    for (int i = 0; i < n; i++)
    {
        int l = std::max(1, i - left[i]);
        int r = std::max(1, right[i] - i);
        sum_mins += a[i] * l * r;
    }

    for (int i = 0; i < n; i++)
        a[i] = -a[i];

    left = GetLeft();
    right = GetRight();

    int sum_maxs = 0;
    for (int i = 0; i < n; i++)
    {
        int l = std::max(1, i - left[i]);
        int r = std::max(1, right[i] - i);
        sum_maxs += (-a[i]) * l * r;
    }

    std::cout << sum_maxs - sum_mins << '\n';

    return 0;
}