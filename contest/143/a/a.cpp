#include <bits/stdc++.h>

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r1, r2;
    std::cin >> r1 >> r2;
    int c1, c2;
    std::cin >> c1 >> c2;
    int d1, d2;
    std::cin >> d1 >> d2;

    auto any_equal = [] (int a, int b, int c, int d) {
        std::set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        s.insert(d);
        return s.size() != 4;
    };

    for (int n1 = 1; n1 <= 9; n1++)
    {
        for (int n2 = 1; n2 <= 9; n2++)
        {
            for (int n3 = 1; n3 <= 9; n3++)
            {
                for (int n4 = 1; n4 <= 9; n4++)
                {
                    if (any_equal(n1, n2, n3, n4)) continue;
                    bool r1_ok = n1 + n2 == r1;
                    bool r2_ok = n3 + n4 == r2;
                    bool c1_ok = n1 + n3 == c1;
                    bool c2_ok = n2 + n4 == c2;
                    bool d1_ok = n1 + n4 == d1;
                    bool d2_ok = n2 + n3 == d2;
                    bool all_ok = r1_ok && r2_ok && c1_ok && c2_ok && d1_ok && d2_ok;
                    if (all_ok)
                    {
                        std::cout << n1 << " " << n2 << "\n" << n3 << " " << n4 << "\n";
                        return 0;
                    }

                }
            }
        }
    }

    std::cout << -1 << "\n";

    return 0;
}
