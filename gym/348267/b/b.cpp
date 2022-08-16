#include <bits/stdc++.h>

#define int int64_t

const int MOD = 1e9 + 7;

int pow(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
    ans %= MOD;
  }
  return ans;
}

void solve() {
  int n, k; std::cin >> n >> k;
  int ans = 0;
  for (int b = 0; b < 32; b++) {
    if ((k >> b) & 1) ans += pow(n, b);
    ans %= MOD;
  }
  std::cout << ans << "\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) solve();


    return 0;
}
