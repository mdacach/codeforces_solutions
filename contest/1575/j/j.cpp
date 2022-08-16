#include <bits/stdc++.h>

#define RIGHT 1
#define DOWN 2
#define LEFT 3

const int INF = 1e9;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        std::cin >> grid[i][j];
      }
    }
    std::vector<int> balls(k);
    for (auto& x : balls) std::cin >> x;

    std::vector<std::set<std::pair<int, int>>> down_intervals(m+1);
    for (int col = 1; col <= m; col++) {
      int l = -1, r = -1;
      bool is_open = false;
      for (int row = 1; row <= n; row++) {
        if (grid[row][col] == DOWN) {
          // create new interval
          if (!is_open) {
            l = row;
            r = row;
            is_open = true;
          } else { // update only r pointer
            r = row;
          }
        } else {
          if (is_open) {
            down_intervals[col].insert({l, r});
            is_open = false;
          }
        }
      }
      // interval was opened all the way down
      if (is_open) {
        down_intervals[col].insert({l, r});
      }
    }

    auto is_down = [&] (int x, int y) {
      if (x > n or x < 1) return false;
      if (y > m or y < 1) return false;
      return grid[x][y] == DOWN;
    };

    auto solve_ball = [&] (int starting_column) {
      int cur_row = 1;
      int cur_col = starting_column;
      start:
      // is this cell a DOWN?
      if (is_down(cur_row, cur_col)) {
        // go down as much as possible
        // find the interval which it is contained
        auto& intervals = down_intervals[cur_col];
        auto previous_itr = std::prev(intervals.upper_bound({cur_row, INF}));
        assert(previous_itr != intervals.end());
        auto [previous_left, previous_right] = *previous_itr;
        cur_row = previous_right+1; // r is still a DOWN
        if (cur_row == n+1) { // out of grid, done
          std::cout << cur_col << " ";
          return;
        }
        // cell will BECOME a DOWN
        // cell immediately before is a DOWN, because we have checked it previously
        // so we need only to see how long to extend this segment below
        if (is_down(cur_row+1, cur_col)) {
          // we gotta merge those two segments
          auto next_itr = std::prev(intervals.upper_bound({cur_row+1, INF}));
          auto [next_left, next_right] = *next_itr;
          std::pair<int, int> new_segment = {previous_left, next_right};
          intervals.erase(previous_itr);
          intervals.erase(next_itr);
          intervals.insert(new_segment);
        } else {
          // we only append this cell to the previous segment
          std::pair<int, int> new_segment = {previous_left, cur_row};
          intervals.erase(previous_itr);
          intervals.insert(new_segment);
        }
        // go to the next column accordingly
        if (grid[cur_row][cur_col] == LEFT) {
          grid[cur_row][cur_col] = DOWN; // becomes a DOWN
          cur_col--;
        } else {
          assert(grid[cur_row][cur_col] == RIGHT);
          grid[cur_row][cur_col] = DOWN; // becomes a DOWN
          cur_col++;
        }
        goto start;
      } else {
        // cell is not a down, so we only merge
        // it's possible we will need to merge only above, only below or both
        auto& intervals = down_intervals[cur_col];
        bool merge_above = is_down(cur_row-1, cur_col);
        bool merge_below = is_down(cur_row+1, cur_col);
        if (merge_above && !merge_below) {
          auto previous_itr = std::prev(intervals.upper_bound({cur_row-1, INF}));
          assert(previous_itr != intervals.end());
          auto [previous_left, previous_right] = *previous_itr;
          std::pair<int, int> new_segment = {previous_left, cur_row};
          intervals.erase(previous_itr);
          intervals.insert(new_segment);
        } else if (!merge_above && merge_below) {
          auto next_itr = std::prev(intervals.upper_bound({cur_row+1, INF}));
          auto [next_left, next_right] = *next_itr;
          std::pair<int, int> new_segment = {cur_row, next_right};
          intervals.erase(next_itr);
          intervals.insert(new_segment);
        } else if (merge_above && merge_below) {
          auto previous_itr = std::prev(intervals.upper_bound({cur_row-1, INF}));
          assert(previous_itr != intervals.end());
          auto [previous_left, previous_right] = *previous_itr;
          auto next_itr = std::prev(intervals.upper_bound({cur_row+1, INF}));
          auto [next_left, next_right] = *next_itr;
          std::pair<int, int> new_segment = {previous_left, next_right};
          intervals.erase(previous_itr);
          intervals.erase(next_itr);
          intervals.insert(new_segment);
        } else {
          // then we just insert this new guy as a single interval
          assert(!merge_above && !merge_below);
          intervals.insert({cur_row, cur_row});
        }

        // go to the next column accordingly
        if (grid[cur_row][cur_col] == LEFT) {
          grid[cur_row][cur_col] = DOWN; // becomes a DOWN
          cur_col--;
        } else {
          assert(grid[cur_row][cur_col] == RIGHT);
          grid[cur_row][cur_col] = DOWN; // becomes a DOWN
          cur_col++;
        }
        goto start;
      }
    };

    for (auto starting_column : balls) {
      solve_ball(starting_column);
    }

    return 0;
}
