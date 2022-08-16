#include <bits/stdc++.h>

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> vertical_streets(n);
    for (auto& x : vertical_streets)
        std::cin >> x;
    std::vector<int> horizontal_streets(m);
    for (auto& x : horizontal_streets)
        std::cin >> x;
    std::vector<std::pair<int, int>> all_points(k);
    for (auto& [x, y] : all_points)
        std::cin >> x >> y;

    std::sort(vertical_streets.begin(), vertical_streets.end());
    std::sort(horizontal_streets.begin(), horizontal_streets.end());

    // remove points that are both in vertical and horizontal
    // split points into horizontal and vertical
    // we can drop the one coordinate
    //    std::vector<std::pair<int, int>> vertical_points;
    std::vector<int> vertical_points;
    //    std::vector<std::pair<int, int>> horizontal_points;
    std::vector<int> horizontal_points;

    std::map<int, std::vector<int>> x_to_vertical_points;
    std::map<int, std::vector<int>> y_to_horizontal_points;

    std::vector<std::pair<int, int>> both_points;
    for (auto [x, y] : all_points)
    {
        auto is_horizontal = std::binary_search(horizontal_streets.begin(), horizontal_streets.end(), y);
        auto is_vertical = std::binary_search(vertical_streets.begin(), vertical_streets.end(), x);
        if (is_horizontal && is_vertical)
            both_points.emplace_back(x, y);
        else if (is_horizontal)
        {
            horizontal_points.push_back(x);
            y_to_horizontal_points[y].push_back(x);
        }
        else if (is_vertical)
        {
            vertical_points.push_back(y);
            x_to_vertical_points[x].push_back(y);
        }
        else
            assert(false);
    }
    std::sort(vertical_points.begin(), vertical_points.end());
    std::sort(horizontal_points.begin(), horizontal_points.end());

    int64_t ans = 0;
    // solve for vertical
    {
        // for each vertical point, which is the street immediately above?
        int processed_counter = 0;
        for (auto y : vertical_points)
        {
            processed_counter++;
            auto street_above = std::lower_bound(horizontal_streets.begin(), horizontal_streets.end(), y);
            if (street_above == horizontal_streets.end())
                break;
            // how many non-processed points are below this street?
            auto points_below = std::upper_bound(vertical_points.begin(), vertical_points.end(), *street_above) -
                                vertical_points.begin();

            ans += points_below - processed_counter;
        }
    }

    // solve for horizontal
    {
        // for each horizontal point, which is the street immediately to the right?
        int processed_counter = 0;
        for (auto x : horizontal_points)
        {
            processed_counter++;
            auto street_to_the_right = std::lower_bound(vertical_streets.begin(), vertical_streets.end(), x);
            if (street_to_the_right == vertical_streets.end())
                break;
            // how many non-processed points are below this street?
            auto points_to_the_left =
                std::upper_bound(horizontal_points.begin(), horizontal_points.end(), *street_to_the_right) -
                horizontal_points.begin();

            ans += points_to_the_left - processed_counter;
        }
    }

    // now we have double counted some points that were in the same line (such as 6 and 7 in sample)
    // so remove them
    // be careful to only group points between two streets, as otherwise it wasn't counted
    {
        for (auto& [y, points] : y_to_horizontal_points)
        {
            // remove points between two vertical streets FUCK this is slow!!
            // O(points * lines)
            // we need to traverse only the points!
            int processed_counter = 0;
            int need_to_remove = 0;
            auto total_points = static_cast<int>(points.size());
            std::sort(points.begin(), points.end());
            for (auto point : points)
            {
                processed_counter++;
                auto street_to_the_right = std::lower_bound(vertical_streets.begin(), vertical_streets.end(), point);
                if (street_to_the_right == vertical_streets.end())
                {
                    need_to_remove += total_points - processed_counter;
                    continue;
                }
                // how many points were here, they were all double counted
                auto points_to_the_left =
                    std::upper_bound(points.begin(), points.end(), *street_to_the_right) - points.begin();
                need_to_remove += points_to_the_left - processed_counter;
            }
            ans -= need_to_remove;
        }
    }

    {
        for (auto& [x, points] : x_to_vertical_points)
        {
            // remove points between two vertical streets FUCK this is slow!!
            // O(points * lines)
            // we need to traverse only the points!
            int processed_counter = 0;
            int need_to_remove = 0;
            auto total_points = static_cast<int>(points.size());
            std::sort(points.begin(), points.end());
            for (auto point : points)
            {
                processed_counter++;
                auto street_above = std::lower_bound(horizontal_streets.begin(), horizontal_streets.end(), point);
                if (street_above == horizontal_streets.end())
                {
                    need_to_remove += total_points - processed_counter;
                    continue;
                }
                // how many points were here, they were all double counted
                auto points_below =
                    std::upper_bound(points.begin(), points.end(), *street_above) - points.begin();
                need_to_remove += points_below - processed_counter;
            }
            ans -= need_to_remove;
        }
    }
    std::cout << ans << "\n";
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
        solve();
}