#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 4 * 1e5;
const ll MOD = 998244353;
ll tree[N], v[N];
void build(ll at, ll L, ll R) {
  if (L == R) {
    tree[at] = v[L];
    return;
  }
  ll mid = (L + R) / 2;
  build(at * 2, L, mid);
  build(at * 2 + 1, mid + 1, R);
  tree[at] = max(tree[at * 2], tree[at * 2 + 1]);
}
ll query(ll at, ll L, ll R, ll l, ll r) {
  if (r < L || R < l) return INT_MIN;
  if (l <= L && R <= r) return tree[at];
  ll mid = (L + R) / 2;
  ll x = query(at * 2, L, mid, l, r);
  ll y = query(at * 2 + 1, mid + 1, R, l, r);
  return max(x, y);
}
int main() {
  ll n, q, l, r, type;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++) {
    cin >> v[i];
  }
  build(1, 1, n);
  while (q--) {
    cin >> type >> l >> r;
    ll ans = 0;
    for (ll i = 1; i <= r - l + 1; i++) {
      ll p = query(1, 1, n, l, l + i - 1);
      ll s = query(1, 1, n, l + i - 1, r);
      ll mult = ((p % MOD) * (s % MOD)) % MOD;
      ans += mult;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}

