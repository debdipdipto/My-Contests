/** This codes provide only 57 points. :( **/
#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t, n, k, type, l, r, q;
  cin >> q;
  vector<pair<ll, ll>> v;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> l >> r;
      v.push_back({l, r});
    } else if (type == 2) {
      cin >> l >> r;
      ll f = 0;
      for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == make_pair(l, r)) {
          f = 1;
          v.erase(it);
          break;
        }
      }
    } else {
      cin >> k;
      ll g = 0, b = 0;
      for (auto i : v) {
        ll m = ceil((i.first + i.second) / 2.0);
        if (k >= i.first && k <= m) g++;
        if (k >= m + 1 && k <= i.second) b++;
      }
      cout << g << " " << b << "\n";
    }
  }
  return 0;
}