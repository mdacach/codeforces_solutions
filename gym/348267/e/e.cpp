#include <bits/stdc++.h>

#define int int64_t

const int MOD = 1e9 + 7;

int mul(int a, int b) {
  return a % MOD * b % MOD;
}

int fexp(int b, int e = MOD-2) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = mul(ans, b);
    b = mul(b, b);
    e = e >> 1;
  }
  return ans;
}


int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k; std::cin >> k;
    int root = 6; // 6 colors for first node
    int from_other_nodes = fexp(4, (fexp(2, k) - 2) % MOD);
    std::cout << mul(root, from_other_nodes) << "\n";

    return 0;
}
