#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct ordered_multiset { // multiset supporting duplicating values in set
int len = 0;
const int ADD = 1000010;
const int MAXVAL = 1000000010;
unordered_map<int, int> mp; // hash = 96814
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

ordered_multiset() { len = 0; T.clear(), mp.clear(); }

inline void insert(int x){
len++, x += MAXVAL;
int c = mp[x]++;
T.insert((x * ADD) + c); }

inline void erase(int x){
x += MAXVAL;
int c = mp[x];
if(c) {
  c--, mp[x]--, len--;
  T.erase((x*ADD) + c); } }

inline int kth(int k){        // 1-based index,  returns the
if(k<1 || k>len) return -1;     // K'th element in the treap,
auto it = T.find_by_order(--k); // -1 if none exists
return ((*it)/ADD) - MAXVAL; }

inline int lower_bound(int x){      // Count of value <x in treap
x += MAXVAL;
int c = mp[x];
return (T.order_of_key((x*ADD)+c)); }

inline int upper_bound(int x){      // Count of value <=x in treap
x += MAXVAL;
int c = mp[x];
return (T.order_of_key((x*ADD)+c)); }

inline int size() { return len; }   // Number of elements in treap
};

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; std::cin >> t;
    while (t--) {
      int n; std::cin >> n;
      std::vector<int> a(n);
      for (auto& x : a) std::cin >> x;
//      ordered_multiset current_elements;
      ordered_set current_elements;
      ordered_set all_elements;
      int t = 0;
      for (auto x : a) all_elements.insert({x, t++});
      t = 0;
      for (auto x : a) {
        current_elements.insert({x, t++});
        int less_left = current_elements.order_of_key({x, 0});
        int less_all = all_elements.order_of_key({x, 0});
        if (
      }
      auto get_smaller = [&] (int x) {
        return current_elements.order_of_key({x, 0});
      };
      int64_t ans = 0;
      for (auto x : a) {
        auto bigger = get_bigger(x);
        auto smaller = get_smaller(x);
        ans += std::min(smaller, bigger);
        current_elements.insert(x);
      }
      std::cout << ans << "\n";
    }

    return 0;
}
