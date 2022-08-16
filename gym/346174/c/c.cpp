#include <bits/stdc++.h>

#define int int64_t

const int N = 4e6 + 5;
int MOD = 1e18;

int dp[N];

int add(int a, int b) {
  return (a + b > MOD ? a + b - MOD : a + b);
}


int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n;
//  std::cin >> n >> m;
//  MOD = m;
  dp[n] = 1;
  int aux = 0;
  std::vector<int> auxs;
  for (int i = n; i >= 1; i--) {
    auxs.push_back(aux);
    dp[i] = add(dp[i], aux);
    {
//    int x = i / 2; // quero que de x
//    int prv = 2;
//    while (false)
//    {
//      int l = prv; // always good
//      int r = n + 1; // always bad
//      while (r - l > 1) {
//        int m = l + (r - l) / 2;
//        int res = i / m;
//        if (res < x) {
//          r = m;
//        } else {
//          l = m;
//        }
//      }
//      int ate = l;
//      int qtd = l - prv + 1;
//      dp[x] = add(dp[x], (1LL * qtd * dp[i]) % m);
//      x = i / (l + 1);
//      prv = l+1;
//      if (l >= i) break;
//    }
    }

    int cheguei = dp[i];
    for(int l = 1, r; l <= i; l = r + 1) {
      int x = i / l;
      r = i / (i / l);
      if (l == 1) continue;
      int qtd = (r - l + 1);
      int somar = qtd * dp[i];
      dp[x] = add(dp[x], (1LL * qtd * dp[i]) % MOD);
      // n / x yields the same value for l <= x <= r
    }
//    for (int j = 2; j <= n; j++) {
//      int floor = i / j;
//      dp[floor] += dp[i];
//      dp[floor] %= m;
//    }
    aux = add(aux, dp[i]);
    int sai = dp[i];
  }
  for (int i = n; i >= 1; i--) {
    std::cout << dp[i] << " ";
  }
  std::cout << "\nauxs: \n";
  for (auto x : auxs) std::cout << x << " ";
  std::vector<int> diff_to_aux;
  std::cout << "\ndiff to aux:\n";
  for (int i = n; i >= 1; i--) {
    std::cout << dp[i] - auxs[n-i] << " ";
  }
  std::cout << "\ndiffs: \n";
  std::vector<int> diffs;
  for (int i = n; i >= 2; i--) {
    diffs.push_back(std::abs(dp[i] - dp[i-1]));
//    std::cout << dp[i] - dp[i-1] << " ";
  }

  for (auto x : diffs) {
    std::cout << x << " ";
  }
  int pot = 0;
  std::vector<int> diff_to_pot;
  std::vector<int> veio_da_sub;
  for (auto x : diffs) {
    diff_to_pot.push_back(x - pot);
    if (pot == 0) pot = 1;
    else pot = 2 * pot;
  }
  std::cout << "\n diff pra pot2:\n";
  for (auto x : diff_to_pot) {
    std::cout << x << " ";
  }
  int sz = diff_to_pot.size();
  std::cout << "\n diff do diff do diff do diff pot 2:\n";
  for (int i = 0; i < sz; i++) {
    std::cout << diffs[i] - diff_to_pot[i] << " ";
  }
  std::cout << "\n";
  std::cout << "\n";
  std::cout << dp[1] << "\n";

  return 0;
}
