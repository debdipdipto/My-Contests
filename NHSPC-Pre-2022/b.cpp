/*
 * @Author : Debdip Das Dipto
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long int
const ll N = 1e5 + 7;
ll pre[N], suff[N];
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  map<ll, vector<pair<ll, ll>>> mp;
  ll n, k;
  cin >> n;
  vector<ll> v(n + 1);
  for (ll i = 1; i <= n; i++) cin >> v[i];
  pre[1] = v[1];
  for (ll i = 2; i <= n; i++) {
    pre[i] = __gcd(pre[i - 1], v[i]);
  }
  suff[n] = v[n];
  for (ll i = n - 1; i >= 1; i--) suff[i] = __gcd(suff[i + 1], v[i]);
  for (ll i = 1; i <= n; i++) {
    ll l = i - 1, r = i + 2;
    ll gcd = __gcd(pre[l], suff[r]);
    mp[gcd].push_back({i, i + 1});
  }
  for (ll i = 0; i <= n; i++) {
    if (mp[i].size()) sort(mp[i].begin(), mp[i].end());
  }
  ll q;
  cin >> q;
  while (q--) {
    cin >> k;
    if (mp[k].size() == 0) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << mp[k][0].first << " " << mp[k][0].second << endl;
    }
  }
  return 0;
}




