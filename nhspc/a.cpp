#include "bits/stdc++.h"
using namespace std;
#define ll long long int
const ll N = 4 * (1e6 + 7);
ll phi[N], mark[N];
void calc(ll n) {
  for (ll i = 1; i <= n; i++) phi[i] = i;
  phi[1] = mark[1] = 1;
  for (ll i = 2; i <= n; i++) {
    if (!mark[i]) {
      for (ll j = i; j <= n; j += i) {
        mark[j] = 1;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}
ll tree[N];
void build(ll n, ll L, ll R) {
  tree[n] = INT_MIN;
  if (L == R) {
    tree[n] = phi[L];
    return;
  }
  ll mid = (L + R) / 2;
  build(n * 2, L, mid);
  build(n * 2 + 1, mid + 1, R);
  tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
}
ll query(ll n, ll L, ll R, ll l, ll r) {
  if (r < L || R < l) return INT_MIN;
  if (l <= L && R <= r) return tree[n];
  ll mid = (L + R) / 2;
  ll x = query(n * 2, L, mid, l, r);
  ll y = query(n * 2 + 1, mid + 1, R, l, r);
  return max(x, y);
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q, k, l, r;
  cin >> n >> q;
  calc(n);
  build(1, 1, n);
  //for (ll i = 1; i <= 200; i++) cout << phi[i] << " ";
  //cout << endl;
  // for (ll i = 1; i <= 4 * n; i++) cout << tree[i] << " ";
  // cout << endl;
  while (q--) {
    cin >> l >> r;
    cout << query(1, 1, n, l, r) << endl;
  }
  return 0;
}



