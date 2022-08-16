#include <bits/stdc++.h>

struct Partition
{
    uint32_t start, end;
    std::vector<int> values;
};

struct PartitionAnswer
{
    uint32_t start, end;
    uint32_t twos;
};

auto solve_for_partition(const Partition& partition) -> PartitionAnswer
{
    // if total product is positive, we are done
    // otherwise, try removing the first negative from the left or right
    // (as we want to make the final array as big as possible)
    const auto& values = partition.values;
    uint32_t negatives = 0;
    for (const auto& x : values)
        negatives += (x < 0);
    // we must keep track of the values 2, as we can't multiply everything here (overflow)
    uint32_t twos = 0;
    for (const auto& x : values)
        twos += (std::abs(x) == 2);

    if (negatives % 2 == 0)
        return { partition.start, partition.end, twos };
    uint32_t from_left = twos;
    uint32_t removed_from_left = 0;
    uint32_t new_start = partition.start;
    uint32_t current_twos = 0;
    for (uint32_t i = 0; i < std::size(values); ++i)
    {
        current_twos += std::abs(values.at(i)) == 2;
        ++removed_from_left;
        if (values.at(i) < 0)
        {
            from_left = twos - current_twos;
            new_start = partition.start + removed_from_left;
            break;
        }
    }
    current_twos = 0;
    uint32_t from_right = twos;
    uint32_t new_end = partition.end;
    uint32_t removed_from_right = 0;
    for (uint32_t i = std::size(values) - 1; i >= 0; --i)
    {
        current_twos += std::abs(values.at(i)) == 2;
        ++removed_from_right;
        if (values.at(i) < 0)
        {
            from_right = twos - current_twos;
            new_end = partition.end - removed_from_right;
            break;
        }
    }
    if (from_left > from_right)
        return { new_start, partition.end, from_left };
    return { partition.start, new_end, from_right };
}

auto solve() -> void
{
    uint32_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)
        std::cin >> x;

    // gotta remove all the zeros first
    // actually we gotta SOLVE for each partition with zeros
    std::vector<Partition> partitions;
    Partition current_partition;
    for (uint32_t i = 0; i < n; ++i)
    {
        // end of a partition
        if (a.at(i) == 0)
        {
            current_partition.end = i - 1;
            if (!current_partition.values.empty())
                partitions.push_back(current_partition);
            current_partition.values.clear();
            continue;
        }

        // partition is starting here
        if (current_partition.values.empty())
            current_partition.start = i;

        current_partition.values.push_back(a.at(i));
    }
    if (!current_partition.values.empty())
    {
        current_partition.end = n - 1;
        partitions.push_back(current_partition);
    }

    uint32_t max_twos = 0;
    uint32_t best_start = 0, best_end = 0;
    for (const auto& partition : partitions)
    {
        const auto result = solve_for_partition(partition);
        if (result.twos > max_twos)
        {
            best_start = result.start;
            best_end = result.end;
            max_twos = result.twos;
        }
    }

    // best to just erase the whole array
    // if answer was 1, we will have the same (empty array -> 1)
    // if answer was 0, we will have it better (by above)
    if (max_twos == 0)
    {
        std::cout << 0 << " " << n << '\n';
        return;
    }
    std::cout << best_start << " " << n - best_end - 1<< '\n';
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