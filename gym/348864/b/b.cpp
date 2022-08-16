#include <bits/stdc++.h>

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> available(n, std::vector<int>(5));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> available[i][j];
    }
  }

  for (int day1 = 0; day1 < 5; day1++) {
    for (int day2 = day1 + 1; day2 < 5; day2++) {
      // try to have one group at day i and another at day j
      // split students from availability
      // a student can be available at one day, available at the other,
      // or both

      std::vector<int> available_at_day1;
      std::vector<int> available_at_day2;
      std::vector<int> available_at_both;
      bool bad_days = false;
      for (int student = 0; student < n; student++) {
        const auto &available_days = available[student];
        if (available_days[day1] && available_days[day2]) {
          available_at_both.push_back(student);
        } else if (available_days[day1]) {
          available_at_day1.push_back(student);
        } else if (available_days[day2]) {
          available_at_day2.push_back(student);
        } else {
          bad_days = true;
          break;
        }
      }
      if (bad_days)
        continue;

      // we need n/2 at each group
      // create for group2
      auto extra_size = available_at_both.size();
      size_t want1 = n / 2;
      want1 -= available_at_day1.size();
      if (want1 > 0) {
        if (extra_size >= want1) {
          extra_size -= want1;
          want1 = 0;
        } else {
          bad_days = true;
        }
      }
      if (bad_days)
        continue;
      size_t want2 = n / 2;
      want2 -= available_at_day2.size();
      if (want2 > 0) {
        if (extra_size >= want2) {
          extra_size -= want2;
          want2 = 0;
        } else {
          bad_days = true;
        }
      }

      if (bad_days)
        continue;

      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
}

int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--)
    solve();

  return 0;
}
