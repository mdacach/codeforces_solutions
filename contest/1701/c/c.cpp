#include <bits/stdc++.h>

auto solve() -> void
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> good(m + 1);
    for (int i = 1; i <= m; ++i)
        std::cin >> good[i];

    std::map<int, std::vector<int>> worker_to_tasks;
    for (int i = 1; i <= m; ++i)
        worker_to_tasks[good[i]].push_back(i);

    auto is_possible = [&](int total_hours)
    {
        std::vector<int> task_is_completed(m + 1);
        std::vector<int> worker_still_available_hours(n + 1, total_hours);
        for (const auto& [worker, tasks] : worker_to_tasks)
        {
            int used_hours = 0;
            for (auto task : tasks)
            {
                used_hours += 1;
                task_is_completed[task] = 1;
                if (used_hours == total_hours)
                    break;
            }
            worker_still_available_hours[worker] -= used_hours;
        }

        int current_worker = 1;
        for (int task = 1; task <= m; ++task)
        {
            if (task_is_completed[task])
                continue;

            auto hours = worker_still_available_hours[current_worker];
            while (hours < 2)
            {
                current_worker += 1;
                if (current_worker > n)
                    return false;
                hours = worker_still_available_hours[current_worker];
            }
            worker_still_available_hours[current_worker] -= 2;
            task_is_completed[task] = 1;
        }
        return true;
    };

    int left = 0;    // left never works
    int right = 4e5; // right always works
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (is_possible(mid))
            right = mid;
        else
            left = mid;
    }
    // in the end, right is the smallest value that works, i.e. our answer
    std::cout << right << '\n';
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