#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k, q, a, b, x;
  cin >> n >> q;
  map<ll, vector<ll>> mp;
  for (ll i = 0; i < n; i++) {
    cin >> k;
    mp[k].push_back(i);
  }
  while (q--) {
    cin >> a >> b >> x;
    auto it = lower_bound(mp[x].begin(), mp[x].end(), a);
    if (it == mp[x].end() || *it > b) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}