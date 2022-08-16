#include <bits/stdc++.h>

const int N = 205;
const int MOD = 1e8;

int ways_footmen[N][N][N]; // {total soldiers, footmen, consecutive footmen}
int ways_riders[N][N][N];  // {total soldiers, riders, consecutive riders}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n1, n2, k1, k2;
    std::cin >> n1 >> n2 >> k1 >> k2;
    ways_footmen[0][0][0] = 1;
//    ways_riders[0][0][0] = 1; // redundant, empty list is covered by above
    auto& f = ways_footmen;
    auto& r = ways_riders;
    for (int total = 0; total < n1 + n2; total++)
    {
        for (int consecutive = 0; consecutive <= std::max(k1, k2); consecutive++)
        {
            for (int of_this_type = 0; of_this_type <= std::max(n1, n2); of_this_type++)
            {
                if (of_this_type > total) break;
                if (consecutive < k1 && of_this_type < n1)
                    ways_footmen[total+1][of_this_type+1][consecutive+1] += ways_footmen[total][of_this_type][consecutive];
                if (consecutive <= k1 && (total - of_this_type) < n2)
                    ways_riders[total+1][total - of_this_type + 1][1] += ways_footmen[total][of_this_type][consecutive];
                if (consecutive < k2 && of_this_type < n2)
                    ways_riders[total+1][of_this_type+1][consecutive+1] += ways_riders[total][of_this_type][consecutive];
                if (consecutive <= k2 && (total - of_this_type) < n1)
                    ways_footmen[total+1][total - of_this_type + 1][1] += ways_riders[total][of_this_type][consecutive];
                ways_footmen[total+1][of_this_type+1][consecutive+1] %= MOD;
                ways_riders[total+1][total - of_this_type + 1][1] %= MOD;
                ways_riders[total+1][of_this_type+1][consecutive+1] %= MOD;
                ways_footmen[total+1][total - of_this_type + 1][1] %= MOD;
            }
        }

        /*
        {
            for (int consecutive_footmen = 0; consecutive_footmen < k1; consecutive_footmen++)
                for (int total_footmen = 0; total_footmen < n1; total_footmen++)
                {
                    ways_footmen[total + 1][total_footmen + 1][consecutive_footmen + 1] +=
                        ways_footmen[total][total_footmen][consecutive_footmen];

                    int new_riders = total + 1 - total_footmen;
                    if (new_riders < n2)
                        ways_riders[total + 1][total + 1 - total_footmen][1] +=
                            ways_footmen[total][total_footmen][consecutive_footmen];
                }
            for (int consecutive_riders = 0; consecutive_riders < k2; consecutive_riders++)
                for (int total_riders = 0; total_riders < n2; total_riders++)
                {
                    ways_riders[total + 1][total_riders + 1][consecutive_riders + 1] +=
                        ways_riders[total][total_riders][consecutive_riders];
                    int new_footmen = total + 1 - total_riders;
                    if (new_footmen < n1)
                        ways_footmen[total + 1][total + 1 - total_riders][1] +=
                            ways_riders[total][total_riders][consecutive_riders];
                }
        }
        */
        continue;
    }
    int ans = 0;
    for (int footmen = 1; footmen <= k1; footmen++)
    {
        ans += ways_footmen[n1 + n2][n1][footmen];
        ans %= MOD;
    }
    for (int riders = 1; riders <= k2; riders++)
    {
        ans += ways_riders[n1 + n2][n2][riders];
        ans %= MOD;
    }
    auto& footmen = ways_footmen;
    auto& riders = ways_riders;
    std::cout << ans << "\n";

    return 0;
}
