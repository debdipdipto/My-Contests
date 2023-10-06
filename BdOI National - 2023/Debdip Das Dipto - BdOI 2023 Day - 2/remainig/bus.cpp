#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  ll n, m, k, q, types, x, y, z;
  cin >> n >> k >> m;
  vector<vector<ll>> queries;
  for (ll i = 0; i < m; i++) {
    cin >> types;
    if (types == 1) {
      cin >> x >> y;
      vector<ll> v = {x, y};
      queries.push_back(v);
    } else if (types == 2) {
      cin >> x >> y >> z;
      vector<ll> v = {x, y, z};
      queries.push_back(v);
    }
  }
  vector<ll> st;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) st.push_back(i);
  for (ll i = 0; i < (1 << n); i++) {
    vector<ll> mp(n + 1, 0);
    for (ll j = 0; j < n; j++) {
      if (i & (1 << j)) {
        mp[st[j]]++;
      }
    }
    ll f = 1;
    for (auto i : queries) {
      if (i.size() == 2) {
        if (mp[i[0]] != mp[i[1]]) f = 0;
      } else if (i.size() == 3) {
        if (!((mp[i[0]] == i[2] && mp[i[1]] == i[2]) || (mp[i[0]] != i[2] && mp[i[1]] != i[2]))) f = 0;
      }
    }
    if (f) ans++;
  }
  cout << ans << endl;

  return 0;
}
