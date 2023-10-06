#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  ll t, n, k;
  cin >> n;
  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    cin >> k;
    v.push_back(k);
  }
  ll ans = 0;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (v[i] == 0) {
      ans += cnt / 2;
      if (cnt & 1) ans++;
      cnt = 0;
    } else {
      cnt++;
    }
  }
  ans += cnt / 2;
  if (cnt & 1) ans++;
  cout << ans << endl;
  return 0;
}
